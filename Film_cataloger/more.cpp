#include "more.h"
#include "ui_more.h"

More::More(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::More)
{
    ui->setupUi(this);

    this->ui->name->setWordWrap(true);
    this->ui->producer->setWordWrap(true);
    this->ui->country->setWordWrap(true);
    this->ui->genre->setWordWrap(true);
    this->ui->description->setWordWrap(true);
    this->ui->year->setWordWrap(true);
}

More::~More()
{
    delete ui;
}

void More::set_film(const Film &film)
{
    this->ui->name->setText(film.getName());
    this->ui->producer->setText(film.getProducer());
    this->ui->country->setText(film.getCountry());
    this->ui->genre->setText(film.getGenre());
    this->ui->description->setText(film.getDescription());
    this->ui->year->setText(QString::number(film.getYear()));
}
