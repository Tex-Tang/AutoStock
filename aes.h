#ifndef AES_H
#define AES_H
#include <QString>
#include <QByteArray>
#include <string>
#include <memory>
#include <openssl/evp.h>

class AES
{
public:
    AES();
    ~AES();

    // Takes a message to be encrypted from |input| along with a human-readable
    // |password| and applies the appropriate cryptographic transformations to
    // produce an OpenSSL-compatible |output|.
    QByteArray Encrypt(const std::string& input, const std::string& password);

    // Takes an OpenSSL-compatible |input| along with a human-readable |password|
    // and applies appropriate decryption transformations to produce the
    // byte-for-byte |output|.
    QByteArray Decrypt(QString input, const std::string& password);

    void PrintSalt() const;
    void PrintKey() const;

private:
    void bzero(unsigned char * s, size_t n);
    void InitEncrypt(const std::string& password);
    void InitDecrypt(const std::string& input, const std::string& password);

    EVP_CIPHER_CTX* encrypt_;
    EVP_CIPHER_CTX* decrypt_;

    // Do not have ownership of these pointers.
    const EVP_CIPHER* cipher_;
    const EVP_MD* digest_;

    std::unique_ptr<unsigned char[]> salt_;
    std::unique_ptr<unsigned char[]> iv_;
    std::unique_ptr<unsigned char[]> key_;

    int nrounds_;
};

#endif // AES_H
