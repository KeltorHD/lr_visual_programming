#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "test.h"

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum class state_type
{
    start = 0,
    one_of_four = 2,
    some_of_four = 3,
    write_answer = 4,
    installation_of_correspondence = 1
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void update_progress_bar();

private slots:
    void on_start_testing_clicked();

    void on_to_test_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* time_line;
    const int seconds{600};
    Test test;

    void enable_buttons(bool enable);
};
#endif // MAINWINDOW_H
