#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "film.h"

#include <QMainWindow>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    /*жанры*/
    QList<QString> genres;
    /*Режиссеры*/
    QList<QString> producers;
    /*Фильмы*/
    QList<Film> films;

    void inputFromFile();
    void saveToFile();
};
#endif // MAINWINDOW_H
