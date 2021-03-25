#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

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
    void on_textEdit_textChanged();

private:
    Ui::MainWindow *ui;
    QString filename;
    bool is_file_open{false};
    bool is_changed{false};

    void new_file();
    void save_file();
    void save_as();
    void open_file();

};
#endif // MAINWINDOW_H
