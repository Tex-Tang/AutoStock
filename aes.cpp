#include "aes.h"

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <QtDebug>
#include <iomanip>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

AES::AES(): encrypt_(EVP_CIPHER_CTX_new()),
    decrypt_(EVP_CIPHER_CTX_new()),
    cipher_(EVP_aes_256_cbc()),
    digest_(EVP_md5()),
    salt_(new unsigned char[8]),
    iv_(new unsigned char[EVP_MAX_IV_LENGTH]),
    key_(new unsigned char[EVP_MAX_KEY_LENGTH]),
    nrounds_(1) {

    EVP_CIPHER_CTX_init(encrypt_);
    EVP_CIPHER_CTX_init(decrypt_);

    bzero(salt_.get(), 8);
    bzero(iv_.get(), EVP_MAX_IV_LENGTH);
    bzero(key_.get(), EVP_MAX_KEY_LENGTH);
}

void AES::bzero(unsigned char * s, size_t n)
{
    unsigned char * c = s; // Can't work with void *s directly.
    size_t i;
    for (i = 0; i < n; ++i)
        c[i] = '\0';
}

QByteArray AES::Encrypt(const std::string& input,
                  const std::string& password) {

    RAND_bytes(salt_.get(), 8);

    EVP_BytesToKey(cipher_,
                   digest_,
                   salt_.get(),
                   reinterpret_cast<const unsigned char*>(password.c_str()),
                   password.length(),
                   nrounds_,
                   key_.get(),
                   iv_.get());

    EVP_EncryptInit_ex(encrypt_,
                       cipher_,
                       NULL,
                       key_.get(),
                       iv_.get());

    int c_len = input.length() + 1 + AES_BLOCK_SIZE;
    int f_len = 0;

    std::unique_ptr<unsigned char[]> ciphertext(new unsigned char[c_len + 1]);
    bzero(ciphertext.get(), c_len + 1);

    EVP_EncryptInit_ex(encrypt_, NULL, NULL, NULL, NULL);

    /* update ciphertext, c_len is filled with the length of ciphertext generated,
   *len is the size of plaintext in bytes */
    EVP_EncryptUpdate(encrypt_,
                      ciphertext.get(),
                      &c_len,
                      reinterpret_cast<const unsigned char *>(input.c_str()),
                      input.length());

    /* update ciphertext with the final remaining bytes */
    EVP_CipherFinal_ex(encrypt_, ciphertext.get() + c_len, &f_len);

    // OpenSSL format. Magic number is "Salted__" followed by the salt and then
    // the ciphertext.
    std::string output;
    output.clear();
    output.append("Salted__");
    output.append(reinterpret_cast<const char *>(salt_.get()),
                  8);
    output.append(reinterpret_cast<const char *>(ciphertext.get()),
                   c_len + f_len);
    return QByteArray::fromStdString(output).toBase64();
}

QByteArray AES::Decrypt(QString text,
                  const std::string& password) {

    // decrypt_.reset(EVP_CIPHER_CTX_new());
    // bzero(salt_.get(), kSaltLen);
    // bzero(iv_.get(), EVP_MAX_IV_LENGTH + 1);
    // bzero(key_.get(), EVP_MAX_KEY_LENGTH + 1);
    const std::string input = QByteArray::fromBase64(text.toUtf8()).toStdString();
    int p_len = input.length() - 16, f_len = 0;
    std::unique_ptr<unsigned char[]> plaintext(new unsigned char[p_len + AES_BLOCK_SIZE + 1]);
    bzero(plaintext.get(), p_len + AES_BLOCK_SIZE + 1);

    // Parse the input string for iv and ciphertext.
    bzero(salt_.get(), 8);
    memcpy(reinterpret_cast<char *>(salt_.get()), input.substr(8, 8).c_str(), 8);

    EVP_BytesToKey(cipher_,
                   digest_,
                   salt_.get(),
                   reinterpret_cast<const unsigned char*>(password.c_str()),
                   password.length(),
                   nrounds_,
                   key_.get(),
                   iv_.get());


    EVP_DecryptInit_ex(decrypt_, cipher_, NULL, key_.get(), iv_.get());

    std::unique_ptr<unsigned char[]> input_ctx(new unsigned char[p_len]);
    memcpy(reinterpret_cast<char *>(input_ctx.get()), input.substr(16).c_str(), p_len);

    int len = p_len;
    EVP_DecryptUpdate(decrypt_,
                      plaintext.get(),
                      &p_len,
                      reinterpret_cast<const unsigned char *>(input_ctx.get()),
                      len);
    EVP_DecryptFinal_ex(decrypt_,
                        plaintext.get() + p_len,
                        &f_len);

    std::string output;
    output.append(reinterpret_cast<const char *>(plaintext.get()), p_len + f_len);

    return QByteArray::fromStdString(output);
}
