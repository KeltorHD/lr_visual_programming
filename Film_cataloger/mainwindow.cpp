#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->inputFromFile();
}

MainWindow::~MainWindow()
{
    this->saveToFile();
    delete ui;
}

void MainWindow::inputFromFile()
{
    /*жанры*/
    QString genre;
    //QFile file("")
}

