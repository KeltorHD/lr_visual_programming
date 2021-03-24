#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    ser[0] = new QBarSet("Продукт1", this);
    ser[1] = new QBarSet("Продукт2", this);
    ser[2] = new QBarSet("Продукт3", this);
    ser[3] = new QBarSet("Продукт4", this);
    ser[4] = new QBarSet("Продукт5", this);

    series = new QBarSeries(this);
    series->append(ser[0]);
    series->append(ser[1]);
    series->append(ser[2]);
    series->append(ser[3]);
    series->append(ser[4]);

    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Гистограмма динамики цен на потребительские продукты");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    categories
            << "2010" << "2011" << "2012"
            << "2013" << "2014" << "2015"
            << "2016" << "2017" << "2018"
            << "2018" << "2020";

    this->costs  = new QLabel("Впишите средние цены товаров по годам: ", this);
    this->costs->setWordWrap(true);
    for (int i = 0; i < categories.size() ; i++)
    {
        this->years[i] = new QLabel(categories.at(i), this);
    }

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    axisY = new QValueAxis();
    axisY->setRange(0,500);
    axisY->setTickCount(15);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->lay->addWidget(chartView);
    ui->lay->removeWidget(this->ui->pushButton_2);
    ui->lay->addWidget(this->ui->pushButton_2);

    /*заполнение*/
    this->names = new QLabel("Введите названия товаров:", this);
    this->ui->lay2->addWidget(this->names);
    this->names_box = new QHBoxLayout(this);
    for (size_t i = 0; i < count_names ; i++)
    {
        this->name_forms[i] = new QFormLayout(this);
        this->name_label[i] = new QLabel("Продукт" + QString::number(i + 1) + ": ", this);
        this->name_edit[i] = new QLineEdit(this->ser[i]->label(), this);

        this->name_forms[i]->addWidget(this->name_label[i]);
        this->name_forms[i]->addWidget(this->name_edit[i]);
        this->names_box->addLayout(this->name_forms[i]);
    }
    this->ui->lay2->addLayout(this->names_box);

    connect(this->name_edit[0], &QLineEdit::textChanged, this, &MainWindow::text1_changed);
    connect(this->name_edit[1], &QLineEdit::textChanged, this, &MainWindow::text2_changed);
    connect(this->name_edit[2], &QLineEdit::textChanged, this, &MainWindow::text3_changed);
    connect(this->name_edit[3], &QLineEdit::textChanged, this, &MainWindow::text4_changed);
    connect(this->name_edit[4], &QLineEdit::textChanged, this, &MainWindow::text5_changed);


    this->ui->lay2->addWidget(this->costs);
    for (size_t i = 0; i < this->labels.size() ; i++)
    {
        this->ui->lay2->addWidget(this->years[i]);

        this->input_layout[i] = new QHBoxLayout(this);

        for (size_t j = 0; j < this->spin_boxes[i].size() ; j++)
        {
            this->forms[i][j] = new QFormLayout(this);
            this->labels[i][j] = new QLabel(ser[j]->label(), this);
            this->spin_boxes[i][j] = new QSpinBox(this);

            this->spin_boxes[i][j]->setRange(0, 500);
            int cost{};
            switch (j)
            {
            case 0:
                cost = 60;
                break;
            case 1:
                cost = 280;
                break;
            case 2:
                cost = 300;
                break;
            case 3:
                cost = 35;
                break;
            case 4:
                cost = 60;
                break;
            }
            cost += i * 2;
            this->spin_boxes[i][j]->setValue(cost);

            this->forms[i][j]->addWidget(this->labels[i][j]);
            this->forms[i][j]->addWidget(spin_boxes[i][j]);
            this->input_layout[i]->addItem(this->forms[i][j]);
        }

        this->ui->lay2->addLayout(this->input_layout[i]);
        this->lines[i] = new QFrame(this);
        this->lines[i]->setFrameShape(QFrame::HLine);
        this->ui->lay2->addWidget(this->lines[i]);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    for (size_t i = 0; i < 5 ; i++)
    {
        this->ser[i]->remove(0, this->spin_boxes.size());
        for (size_t j = 0; j < this->spin_boxes.size() ; j++ )
        {
            *this->ser[i] << this->spin_boxes[j][i]->value();
        }
    }
    this->ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::text1_changed(QString str)
{
    this->set_pr_name(str, 0);
}
void MainWindow::text2_changed(QString str)
{
    this->set_pr_name(str, 1);
}

void MainWindow::text3_changed(QString str)
{
    this->set_pr_name(str, 2);
}

void MainWindow::text4_changed(QString str)
{
    this->set_pr_name(str, 3);
}

void MainWindow::text5_changed(QString str)
{
    this->set_pr_name(str, 4);
}

void MainWindow::set_pr_name(QString name, int count)
{
    this->ser[count]->setLabel(name);
    for (size_t i = 0; i < count_years ; i++)
    {
        this->labels[i][count]->setText(name);
    }
}

