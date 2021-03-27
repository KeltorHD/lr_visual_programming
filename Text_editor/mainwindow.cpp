#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vector>
#include <regex>
#include <string>
#include <algorithm>

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

    connect(ui->hrefs_show, &QAction::triggered,this,&MainWindow::hrefs_show);

    this->hrefs = new Hrefs(this);
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
    }

    this->ui->textEdit->clear();
    this->is_file_open = false;
    this->filename.clear();
    this->is_changed = false;
    this->setWindowTitle("Текстовый редактор");
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
            this->is_file_open = true;
        }
    }
    this->is_changed = false;
    this->setWindowTitle("Текстовый редактор: " + this->filename);
}

void MainWindow::save_as()
{
    QString tmp_name = QFileDialog::getSaveFileName(this, tr("Save file as"), "", tr("Text Files (*.txt)"));

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
    this->is_file_open = true;
    this->setWindowTitle("Текстовый редактор: " + this->filename);
}

void MainWindow::open_file()
{
    if (this->is_changed) /*если файлик изменен*/
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
            this->is_file_open = false;
        }
        else /*сохраняем в новый файлик*/
        {
            QString tmp_name = QFileDialog::getSaveFileName(this, tr("Save file"), "", tr("Text Files (*.txt)"));

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
        }
    }

    this->ui->textEdit->clear();

    /*открываем файлик*/
    QString tmp_name = QFileDialog::getOpenFileName(this, tr("Open file"), "", tr(""));

    if (!tmp_name.isNull())
    {
        QFile file(tmp_name);
        if (!file.open(QIODevice::ReadOnly))
        {
            file.close();
            // error message
        }
        else
        {
            QTextStream stream(&file);
            //stream.setCodec("UTF-8");
            stream.setGenerateByteOrderMark(false);
            this->ui->textEdit->setPlainText(stream.readAll());
            stream.flush();
            file.close();
        }
    }
    this->filename = tmp_name;
    this->is_file_open = true;
    this->is_changed = false;
    this->setWindowTitle("Текстовый редактор: " + this->filename);
}

void MainWindow::hrefs_show()
{
    std::string to_find{this->ui->textEdit->toPlainText().toStdString()};

    std::regex href_reg(R"foo(href="([^""']*)")foo");
    std::regex src_reg(R"foo(src="([^""']*)")foo");
    std::vector<std::string> href
    {
        std::sregex_token_iterator{to_find.begin(), to_find.end(), href_reg, 0}, // Mark `0` here i.e. whole regex match
        std::sregex_token_iterator{}
    };
    std::vector<std::string> image
    {
        std::sregex_token_iterator{to_find.begin(), to_find.end(), src_reg, 0}, // Mark `0` here i.e. whole regex match
        std::sregex_token_iterator{}
    };

    for_each(href.begin(), href.end(), [](std::string& str){str.erase(0,6); str.erase(str.end()-1);});
    for_each(image.begin(), image.end(), [](std::string& str){str.erase(0,5); str.erase(str.end()-1);});

    this->hrefs->set_data(href, image);
    this->hrefs->show();
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
