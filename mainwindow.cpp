#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ddecomm.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DdeComm* dde2 = new DdeComm;
    DdeComm* dde1 = new DdeComm;
    unsigned long long conv1 = dde1->open("SIDE","MY");
    unsigned long long conv2 = dde2->open("SIDE","MY");
    dde1->advise(conv1,"Hello");
    dde2->advise(conv2,"Hello2");
}

MainWindow::~MainWindow()
{
    delete ui;
}

