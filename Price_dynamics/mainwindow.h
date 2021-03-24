#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBarSeries>
#include <QBarSet>
#include <QChart>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QChartView>
#include <QLabel>
#include <array>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFormLayout>
#include <QSpinBox>
#include <QLineEdit>

using namespace QtCharts;

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    std::array<QBarSet*, 5> ser;
    QBarSeries *series;
    QChart *chart;
    QStringList categories;
    QValueAxis *axisY;

    static const size_t count_names{5};
    static const size_t count_years{11};

    /*для заполнения*/
    QLabel* names;
    std::array<QFormLayout*, count_names> name_forms;
    QHBoxLayout* names_box;
    std::array<QLineEdit*, count_names> name_edit;
    std::array<QLabel*, count_names> name_label;
    QLabel* costs;
    std::array<QLabel*, count_years> years;
    std::array<QHBoxLayout*, count_years> input_layout;
    std::array<std::array<QSpinBox*, count_names>, count_years> spin_boxes;
    std::array<std::array<QLabel*, count_names>, count_years> labels;
    std::array<std::array<QFormLayout*, count_names>, count_years> forms;
    std::array<QFrame*, count_years> lines;

    void text1_changed(QString str);
    void text2_changed(QString str);
    void text3_changed(QString str);
    void text4_changed(QString str);
    void text5_changed(QString str);

    void set_pr_name(QString name, int count);

};
#endif // MAINWINDOW_H
