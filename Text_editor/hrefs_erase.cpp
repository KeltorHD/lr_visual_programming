#include "hrefs_erase.h"
#include "ui_hrefs_erase.h"

#include <regex>
#include <algorithm>

Hrefs_erase::Hrefs_erase(QTextEdit* text, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hrefs_erase)
{
    ui->setupUi(this);
    this->text = text;
}

Hrefs_erase::~Hrefs_erase()
{
    delete ui;
}

void Hrefs_erase::on_pushButton_2_clicked()
{
    this->close();
}

void Hrefs_erase::on_pushButton_clicked()
{
    std::string to_find{this->text->toPlainText().toStdString()};

    std::regex href_reg(R"foo(href="([^""']*)")foo");
    std::regex src_reg(R"foo(src="([^""']*)")foo");
    std::vector<std::string> href
    {
        std::sregex_token_iterator{to_find.begin(), to_find.end(), href_reg, 0}, // Mark `0` here i.e. whole regex match
        std::sregex_token_iterator{}
    };
    std::vector<std::string> image
    {
        std::sregex_token_iterator{to_find.begin(), to_find.end(), src_reg, 0}, // Mark `0` here i.e. whole regex match
        std::sregex_token_iterator{}
    };

    for_each(href.begin(), href.end(), [](std::string& str){str.erase(0,6); str.erase(str.end()-1);});
    for_each(image.begin(), image.end(), [](std::string& str){str.erase(0,5); str.erase(str.end()-1);});

    for (size_t i = 0; i < href.size() ; i++)
    {
        std::string to_add{this->ui->lineEdit->text().toStdString() + "/"};

        auto it = to_find.find(href[i]);
        if (it != std::string::npos)

        {
            auto end = it + href[i].size();
            auto j = end;
            for (; j > it; j--)
            {
                if (to_find[j] == ':' || to_find[j] =='/' || to_find[j] == '\\')
                    break;
            }
            for (auto k = (to_find[j] == '/' ? j+1 : j); k < end ; k++)
            {
                to_add += to_find[k];
            }

            to_find.erase(it, href[i].size());
            to_find.insert(it, to_add);
        }
    }

    for (size_t i = 0; i < image.size() ; i++)
    {
        std::string to_add{this->ui->lineEdit->text().toStdString() + "/"};

        auto it = to_find.find(image[i]);
        if (it != std::string::npos)

        {
            auto end = it + image[i].size();
            auto j = end;
            for (; j > it; j--)
            {
                if (to_find[j] == ':' || to_find[j] =='/' || to_find[j] == '\\')
                    break;
            }
            for (auto k = (to_find[j] == '/' ? j+1 : j); k < end ; k++)
            {
                to_add += to_find[k];
            }

            to_find.erase(it, image[i].size());
            to_find.insert(it, to_add);
        }
    }

    this->text->setPlainText(QString::fromStdString(to_find));

    this->close();
}

void Hrefs_erase::on_lineEdit_textChanged(const QString &arg1)
{
    if (!arg1.isEmpty())
    if (    arg1[arg1.size() - 1] == '\\'
            ||
            arg1[arg1.size() - 1] == '/'
            ||
            arg1[arg1.size() - 1] == ':'
            ||
            arg1[arg1.size() - 1] == '*'
            ||
            arg1[arg1.size() - 1] == '?'
            ||
            arg1[arg1.size() - 1] == '<'
            ||
            arg1[arg1.size() - 1] == '>'
            ||
            arg1[arg1.size() - 1] == '|')
    {
        this->ui->lineEdit->setText(arg1.left(arg1.size() - 1));
    }
}
