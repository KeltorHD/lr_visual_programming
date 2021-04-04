#include "change.h"
#include "ui_change.h"

Change::Change(QListWidget* w, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Change)
{
    ui->setupUi(this);

    this->w = w;
}

Change::~Change()
{
    delete ui;
}

void Change::set_film(Film* film, const QStringList &genres, const QStringList &producers)
{
    this->film = film;

    this->ui->name->setText(film->getName());
    this->ui->country->setText(film->getCountry());
    this->ui->year->setValue(film->getYear());
    this->ui->description->setText(film->getDescription());

    this->ui->genre->addItems(genres);
    this->ui->genre->setCurrentIndex(genres.indexOf(film->getGenre()));

    this->ui->producer->addItems(producers);
    this->ui->producer->setCurrentIndex(producers.indexOf(film->getProducer()));
}

void Change::on_pushButton_2_clicked()
{
    this->close();
}

void Change::on_pushButton_clicked()
{
    QString title{this->film->getText()};

    this->film->setName(this->ui->name->text());
    this->film->setCountry(this->ui->country->text());
    this->film->setYear(this->ui->year->text().toInt());
    this->film->setDescription(this->ui->description->text());

    this->film->setGenre(this->ui->genre->currentText());
    this->film->setProducer(this->ui->producer->currentText());

    this->w->findItems(title, Qt::MatchExactly)[0]->setText(this->film->getText());

    this->close();
}
