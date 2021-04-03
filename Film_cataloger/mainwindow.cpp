#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>

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
    QFile file(":/genres.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        throw "not open file";

    QTextStream file_stream(&file);
    size_t count{file_stream.readLine().toULongLong()};
    for (size_t i = 0; i < count; i++)
    {
        this->genres.push_back(file_stream.readLine());
    }

    this->ui->genres->addItems(this->genres);
    file.close();
}

void MainWindow::saveToFile()
{

}

