#ifndef FILM_H
#define FILM_H

#include <QString>

class Film
{
public:
    Film(QString name,  QString producer, QString country, QString description, int year);

    QString getName() const;
    void setName(const QString &value);

    QString getProducer() const;
    void setProducer(const QString &value);

    QString getCountry() const;
    void setCountry(const QString &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    int getYear() const;
    void setYear(int value);

private:
    QString name;
    QString producer;
    QString country;
    QString description;
    int year;
};

#endif // FILM_H
