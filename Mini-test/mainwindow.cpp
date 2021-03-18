#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->test.init();

    this->time_line = new QTimer(this);
    this->ui->progress_bar->setRange(0, seconds);
    ui->tabWidget->setCurrentIndex(0);
    ui->type_answers->setCurrentIndex(int(state_type::start));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enable_buttons(bool enable)
{
    ui->progress_bar->setEnabled(enable);
    ui->next_button->setEnabled(enable);
    ui->prev_button->setEnabled(enable);
    ui->check_button->setEnabled(enable);
}

void MainWindow::update_progress_bar()
{
    if (this->ui->progress_bar->value() >= seconds)
    {
        this->time_line->stop();
        this->enable_buttons(false);
        ui->tabWidget->setCurrentIndex(2);
        ui->type_answers->setCurrentIndex(int(state_type::start));
    }
    else
    {
        this->ui->progress_bar->setValue(this->ui->progress_bar->value() + 1);
    }
}

void MainWindow::on_start_testing_clicked()
{
    this->enable_buttons(true);
    this->time_line->start(1000);
    connect(time_line, &QTimer::timeout, this, &MainWindow::update_progress_bar);

    this->test.reset();
    this->ui->type_answers->setCurrentIndex(int(state_type(this->test.get_current_type())));
}

void MainWindow::on_to_test_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}
