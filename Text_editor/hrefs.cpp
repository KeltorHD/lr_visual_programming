#include "hrefs.h"
#include "ui_hrefs.h"

Hrefs::Hrefs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hrefs)
{
    ui->setupUi(this);
}

Hrefs::~Hrefs()
{
    delete ui;
}

void Hrefs::set_data(std::vector<std::string> href, std::vector<std::string> images)
{
    this->ui->list_href->clear();
    this->ui->list_image->clear();
    for (size_t i = 0; i < href.size() ; i++)
    {
        this->ui->list_href->addItem(QString::fromUtf8(href[i].c_str()));
    }
    for (size_t i = 0; i < images.size() ; i++)
    {
        this->ui->list_image->addItem(QString::fromUtf8(images[i].c_str()));
    }
}
