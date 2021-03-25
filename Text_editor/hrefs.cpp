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

void Hrefs::set_data(std::vector<QString> href, std::vector<QString> images)
{
    for (size_t i = 0; i < href.size() ; i++)
    {
        this->ui->list_href->addItem(href[i]);
    }
    for (size_t i = 0; i < images.size() ; i++)
    {
        this->ui->list_image->addItem(images[i]);
    }
}
