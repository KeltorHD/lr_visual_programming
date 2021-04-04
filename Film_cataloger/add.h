#ifndef ADD_H
#define ADD_H

#include "film.h"

#include <QDialog>
#include <QListWidget>

namespace Ui {
class Add;
}

class Add : public QDialog
{
    Q_OBJECT

public:
    explicit Add(QListWidget* w, QList<Film>& films, QWidget *parent = nullptr);
    ~Add();

    void set_context(const QStringList& genres,const QStringList& producers);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Add *ui;
    QListWidget* w;
    QList<Film>& films;
};

#endif // ADD_H
