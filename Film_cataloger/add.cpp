#include "add.h"
#include "ui_add.h"

Add::Add(QListWidget* w, QList<Film>& films, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::Add), films(films)
{
    ui->setupUi(this);

    this->w = w;
}

Add::~Add()
{
    delete ui;
}

void Add::set_context(const QStringList &genres, const QStringList &producers)
{
    this->ui->genre->addItems(genres);
    this->ui->producer->addItems(producers);
}

void Add::on_pushButton_2_clicked()
{
    this->close();
}

void Add::on_pushButton_clicked()
{
    if (this->ui->name->text().size())
    {
        Film film;
        film.setName(this->ui->name->text());
        film.setCountry(this->ui->country->text());
        film.setYear(this->ui->year->text().toInt());
        film.setDescription(this->ui->description->text());

        film.setGenre(this->ui->genre->currentText());
        film.setProducer(this->ui->producer->currentText());

        this->films.push_back(film);
        this->w->addItem(film.getText());

        this->close();
    }
}
