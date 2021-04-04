#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "film.h"

#include <QMainWindow>
#include <QList>
#include <QStringList>
#include <map>
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_clear_genre_clicked();

    void on_clear_producer_clicked();

    //void on_genres_currentRowChanged(int currentRow);

    //void on_producers_currentRowChanged(int currentRow);


    void on_genres_itemClicked(QListWidgetItem *item);

    void on_producers_itemClicked(QListWidgetItem *item);

    void on_films_itemClicked(QListWidgetItem *item);

    void on_del_object_clicked();

private:
    Ui::MainWindow *ui;

    /*жанры*/
    QStringList genres;
    bool sel_genre{false};
    /*Режиссеры*/
    QStringList producers;
    bool sel_producer{false};
    /*Фильмы*/
    QList<Film> films;
    QStringList films_text;

    void inputFromFile();
    void saveToFile();

    QStringList selected_film(std::map<QString, QString> category);

    void set_button_enabled(bool enable);
    void set_films();
};
#endif // MAINWINDOW_H
