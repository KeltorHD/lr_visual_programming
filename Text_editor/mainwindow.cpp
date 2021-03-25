#include "mainwindow.h"
#include "ui_mainwindow.h"

static bool first{true};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->new_file, &QAction::triggered,this,&MainWindow::new_file);
    connect(ui->open_file, &QAction::triggered,this,&MainWindow::open_file);
    connect(ui->save_file, &QAction::triggered,this,&MainWindow::save_file);
    connect(ui->save_as, &QAction::triggered,this,&MainWindow::save_as);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::new_file()
{
    if (this->is_changed)
    {
        QString tmp_name = QFileDialog::getSaveFileName(this, tr("Save new file"), "", tr("Text Files (*.txt)"));

        if (!tmp_name.isNull())
        {
            QFile file(tmp_name);
            if (!file.open(QIODevice::WriteOnly))
            {
                file.close();
                // error message
            }
            else
            {
                QTextStream stream(&file);
                //stream.setCodec("UTF-8");
                stream.setGenerateByteOrderMark(false);
                stream << this->ui->textEdit->toPlainText();
                stream.flush();
                file.close();
            }
        }

        this->is_changed = false;
        this->ui->textEdit->clear();
    }
    else
    {
        this->ui->textEdit->clear();
    }
}

void MainWindow::save_file()
{
    if (this->is_changed)
    {
        if (this->is_file_open) /*сохранение в тот же файлик*/
        {
            QFile file(this->filename);

            if (!file.open(QIODevice::WriteOnly))
            {
                file.close();
            }
            else
            {
                QTextStream stream(&file);
                //stream.setCodec("UTF-8");
                stream.setGenerateByteOrderMark(false);
                stream << this->ui->textEdit->toPlainText();
                stream.flush();
                file.close();
            }

            this->is_changed = false;
        }
        else
        {
            QString tmp_name = QFileDialog::getSaveFileName(this, tr("Save new file"), "", tr("Text Files (*.txt)"));

            if (!tmp_name.isNull())
            {
                QFile file(tmp_name);
                if (!file.open(QIODevice::WriteOnly))
                {
                    file.close();
                    // error message
                }
                else
                {
                    QTextStream stream(&file);
                    //stream.setCodec("UTF-8");
                    stream.setGenerateByteOrderMark(false);
                    stream << this->ui->textEdit->toPlainText();
                    stream.flush();
                    file.close();
                }
            }

            this->is_changed = false;
            this->filename = tmp_name;
        }
    }
}

void MainWindow::save_as()
{
    QString tmp_name = QFileDialog::getSaveFileName(this, tr("Save new file"), "", tr("Text Files (*.txt)"));

    if (!tmp_name.isNull())
    {
        QFile file(tmp_name);
        if (!file.open(QIODevice::WriteOnly))
        {
            file.close();
            // error message
        }
        else
        {
            QTextStream stream(&file);
            //stream.setCodec("UTF-8");
            stream.setGenerateByteOrderMark(false);
            stream << this->ui->textEdit->toPlainText();
            stream.flush();
            file.close();
        }
    }

    this->is_changed = false;
    this->ui->textEdit->clear();
    this->filename = tmp_name;
}

void MainWindow::open_file()
{

}

void MainWindow::on_textEdit_textChanged()
{
    if (first)
    {
        first = false;
    }
    else
    {
        this->is_changed = true;
    }
}
