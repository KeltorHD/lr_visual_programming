#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "test.h"

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QFrame>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum class state_type
{
    start = 0,
    one_of_four = 1,
    some_of_four = 2,
    write_answer = 3,
    installation_of_correspondence = 4
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

    void on_next_button_clicked();

    void on_prev_button_clicked();

    void on_check_button_clicked();

    void on_answer1_clicked();

    void on_answer2_clicked();

    void on_answer3_clicked();

    void on_answer4_clicked();

    void on_to_show_clicked();

    void on_done_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* time_line;
    const int seconds{60};
    Test test;
    /*отображение текста*/
    QLabel* result;
    std::array<QLabel*, 10> questions;
    std::array<QLabel*, 10> results;
    std::array<QFrame*, 11> lines;

    void enable_buttons(bool enable);

    void fill_question();
};
#endif // MAINWINDOW_H
