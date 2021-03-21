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

void MainWindow::fill_question()
{
    this->ui->question->setText(this->test.get_question());
    this->ui->question_2->setText(this->test.get_question());
    this->ui->question_3->setText(this->test.get_question());
    this->ui->question_4->setText(this->test.get_question());

    switch (this->test.get_current_type())
    {
    case test_type::one_of_four:
        ui->answer1->setText(this->test.get_answers_1()[0]);
        ui->answer2->setText(this->test.get_answers_1()[1]);
        ui->answer3->setText(this->test.get_answers_1()[2]);
        ui->answer4->setText(this->test.get_answers_1()[3]);
        break;
    case test_type::some_of_four:
        ui->answer1_2->setText(this->test.get_answers_2()[0]);
        ui->answer2_2->setText(this->test.get_answers_2()[1]);
        ui->answer3_2->setText(this->test.get_answers_2()[2]);
        ui->answer4_2->setText(this->test.get_answers_2()[3]);
        break;
    case test_type::write_answer:
        break;
    case test_type::installation_of_correspondence:
        ui->text1->setText(this->test.get_answers_4().first[0]);
        ui->text2->setText(this->test.get_answers_4().first[1]);
        ui->text3->setText(this->test.get_answers_4().first[2]);
        ui->text4->setText(this->test.get_answers_4().first[3]);
        auto arr{this->test.get_answers_4().second};
        for (size_t i = 0; 4; i++)
        {
            ui->combo1->addItem(arr[i]);
            ui->combo2->addItem(arr[i]);
            ui->combo3->addItem(arr[i]);
            ui->combo4->addItem(arr[i]);
        }
        break;
    }
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
    this->fill_question();
}

void MainWindow::on_to_test_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_next_button_clicked()
{
    if (this->test.get_current_index() < 9)
    {
        this->test.set_current_index(this->test.get_current_index());
    }
    this->ui->type_answers->setCurrentIndex(int(state_type(this->test.get_current_type())));
    this->fill_question();
}
