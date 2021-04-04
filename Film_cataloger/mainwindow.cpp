#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->inputFromFile();

    this->more = new More(this);
    this->change = new Change(this->ui->films, this);
    this->add = new Add(this->ui->films, this->films, this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inputFromFile()
{
    /*жанры*/
    QFile file_genre("genres.txt");

    if (!file_genre.open(QIODevice::ReadOnly | QIODevice::Text))
        throw "not open file";

    QTextStream file_genre_stream(&file_genre);
    size_t count_genre{file_genre_stream.readLine().toULongLong()};
    for (size_t i = 0; i < count_genre; i++)
    {
        this->genres.push_back(file_genre_stream.readLine());
    }

    this->ui->genres->addItems(this->genres);
    file_genre.close();

    /*режиссеры*/
    QFile file_producers("producers.txt");

    if (!file_producers.open(QIODevice::ReadOnly | QIODevice::Text))
        throw "not open file";

    QTextStream file_producers_stream(&file_producers);
    size_t count_producers{file_producers.readLine().toULongLong()};
    for (size_t i = 0; i < count_producers; i++)
    {
        QString prod{file_producers.readLine()};
        this->producers.push_back(prod.left(prod.length() - 1));
    }

    this->ui->producers->addItems(this->producers);
    file_producers.close();

    /*фильмы*/
    QFile file_films("films.txt");

    if (!file_films.open(QIODevice::ReadOnly | QIODevice::Text))
        throw "not open file";

    QTextStream file_films_stream(&file_films);
    size_t count_films{file_films_stream.readLine().toULongLong()};
    for (size_t i = 0; i < count_films; i++)
    {
        Film film;
        film.input(file_films_stream);
        this->films.push_back(film);
        this->films_text.push_back(film.getText());
    }

    this->ui->films->addItems(this->films_text);
    file_films.close();
}

void MainWindow::saveToFile()
{
    QFile file_genres("genres.txt");
    file_genres.open(QIODevice::WriteOnly);

    QTextStream stream_genres(&file_genres);
    stream_genres << this->genres.size() << "\n";
    for (qsizetype i = 0; i < this->genres.size(); i++)
    {
        stream_genres << this->genres[i] << "\n";
    }
    file_genres.close();

    QFile file_producers("producers.txt");
    file_producers.open(QIODevice::WriteOnly);

    QTextStream stream_producers(&file_producers);
    stream_producers << this->producers.size() << "\n";
    for (qsizetype i = 0; i < this->producers.size(); i++)
    {
        stream_producers << this->producers[i] << "\n";
    }
    file_producers.close();

    QFile file_films("films.txt");
    file_films.open(QIODevice::WriteOnly);

    QTextStream stream_films(&file_films);
    stream_films << this->films.size() << "\n";
    for (qsizetype i = 0; i < this->films.size(); i++)
    {
        stream_films << this->films[i];
    }
    file_films.close();
}

QStringList MainWindow::selected_film(std::map<QString, QString> category)
{
    QStringList selected{};
    for (auto& i: this->films)
    {
        if (category.size() == 2)
        {
            if (i.getGenre() == category["genre"] && i.getProducer() == category["producer"])
                selected.push_back(i.getText());
        }
        else if (category.size() == 1)
        {
            if (category.find("genre") != category.end())
            {
                if (i.getGenre() == category["genre"])
                    selected.push_back(i.getText());
            }
            else if (category.find("producer") != category.end())
            {
                if (i.getProducer() == category["producer"])
                    selected.push_back(i.getText());
            }
        }
        else
        {
            selected.push_back(i.getText());
        }
    }

    return selected;
}

void MainWindow::set_button_enabled(bool enable)
{
    this->ui->del_object->setEnabled(enable);
    this->ui->change_object->setEnabled(enable);
    this->ui->more_object->setEnabled(enable);
}

void MainWindow::set_films()
{
    std::map<QString, QString> sort;
    if (this->sel_genre)
    {
        sort["genre"] = this->genres[this->ui->genres->currentRow()];
    }
    if (this->sel_producer)
    {
        sort["producer"] = this->producers[this->ui->producers->currentRow()];
    }
    this->ui->films->clear();
    this->ui->films->addItems(this->selected_film(sort));
    this->set_button_enabled(false);
}


void MainWindow::on_clear_genre_clicked()
{
    std::map<QString, QString> sort;
    this->ui->genres->clearSelection();

    if (this->sel_producer)
    {
        sort["producer"] = this->producers[this->ui->producers->currentRow()];
    }

    this->sel_genre = false;
    this->set_button_enabled(false);
    this->ui->films->clear();
    this->ui->films->addItems(this->selected_film(sort));
}

void MainWindow::on_clear_producer_clicked()
{
    this->ui->producers->clearSelection();
    std::map<QString, QString> sort;

    if (this->sel_genre)
    {
        sort["genre"] = this->genres[this->ui->genres->currentRow()];
    }

    this->sel_producer = false;
    this->ui->films->clear();
    this->set_button_enabled(false);
    this->ui->films->addItems(this->selected_film(sort));
}

void MainWindow::on_genres_itemClicked(QListWidgetItem *item)
{
    std::map<QString, QString> sort;
    sort["genre"] = item->text();

    if (this->sel_producer)
    {
        sort["producer"] = this->producers[this->ui->producers->currentRow()];
    }

    this->sel_genre = true;
    this->ui->films->clear();
    this->set_button_enabled(false);
    this->ui->films->addItems(this->selected_film(sort));
}

void MainWindow::on_producers_itemClicked(QListWidgetItem *item)
{
    std::map<QString, QString> sort;
    sort["producer"] = item->text();

    if (this->sel_genre)
    {
        sort["genre"] = this->genres[this->ui->genres->currentRow()];
    }

    this->sel_producer = true;
    this->ui->films->clear();
    this->set_button_enabled(false);
    this->ui->films->addItems(this->selected_film(sort));
}

void MainWindow::on_films_itemClicked(QListWidgetItem*)
{
    this->set_button_enabled(true);
}

void MainWindow::on_del_object_clicked()
{
    for (qsizetype i = 0; i < this->films.size(); i++)
    {
        if (this->films[i].getText() == this->ui->films->currentItem()->text())
        {
            this->films.remove(i);

            this->set_films();

            break;
        }
    }
}

void MainWindow::on_more_object_clicked()
{
    for (qsizetype i = 0; i < this->films.size(); i++)
    {
        if (this->films[i].getText() == this->ui->films->currentItem()->text())
        {
            this->more->set_film(this->films[i]);
            this->more->show();

            break;
        }
    }
}

void MainWindow::on_change_object_clicked()
{
    for (qsizetype i = 0; i < this->films.size(); i++)
    {
        if (this->films[i].getText() == this->ui->films->currentItem()->text())
        {
            this->change->set_film(&this->films[i], this->genres, this->producers);
            this->change->show();

            this->set_films();

            break;
        }
    }
}

void MainWindow::on_add_clicked()
{
    this->add->set_context(this->genres, this->producers);
    this->add->show();
}

void MainWindow::on_pushButton_clicked()
{
    this->saveToFile();
}
