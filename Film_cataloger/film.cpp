#include "film.h"

Film::Film(QString name,  QString producer, QString country, QString genre, QString description, int  year)
    :name(name), producer(producer), country(country), description(description), year(year), genre(genre)
{

}

QString Film::getName() const
{
    return name;
}

void Film::setName(const QString &value)
{
    name = value;
}

QString Film::getProducer() const
{
    return producer;
}

void Film::setProducer(const QString &value)
{
    producer = value;
}

QString Film::getCountry() const
{
    return country;
}

void Film::setCountry(const QString &value)
{
    country = value;
}

QString Film::getDescription() const
{
    return description;
}

void Film::setDescription(const QString &value)
{
    description = value;
}

int Film::getYear() const
{
    return year;
}

void Film::setYear(int value)
{
    year = value;
}

QString Film::getGenre() const
{
    return genre;
}

void Film::setGenre(const QString &value)
{
    genre = value;
}

QString Film::getText() const
{
    return this->name + " (" + QString::number(this->year) + ")";
}

void Film::input(QTextStream &file)
{
    this->name = file.readLine();
    this->producer = file.readLine();
    this->country = file.readLine();
    this->genre = file.readLine();
    this->year = file.readLine().toInt();
    this->description = file.readLine();
}

QTextStream &operator<<(QTextStream& stream, const Film& film)
{
    stream<<film.name<< "\n";
    stream<<film.producer<< "\n";
    stream<<film.country<< "\n";
    stream<<film.genre<< "\n";
    stream<<film.year<< "\n";
    stream<<film.description<< "\n";
    return stream;
}
