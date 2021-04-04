#ifndef CHANGE_H
#define CHANGE_H

#include "film.h"

#include <QDialog>
#include <QListWidget>

namespace Ui {
class Change;
}

class Change : public QDialog
{
    Q_OBJECT

public:
    explicit Change(QListWidget* w, QWidget *parent = nullptr);
    ~Change();

    void set_film(Film* film, const QStringList& genres, const QStringList& producers);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Change *ui;
    QListWidget* w;
    Film* film;

};

#endif // CHANGE_H
