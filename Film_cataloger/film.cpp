#include "film.h"

Film::Film(QString name,  QString producer, QString country, QString description, int year)
    :name(name), producer(producer), country(country), description(description), year(year)
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
