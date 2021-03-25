#ifndef HREFS_H
#define HREFS_H

#include <QDialog>
#include <QString>
#include <vector>

namespace Ui {
class Hrefs;
}

class Hrefs : public QDialog
{
    Q_OBJECT

public:
    explicit Hrefs(QWidget *parent = nullptr);
    ~Hrefs();

    void set_data(std::vector<QString> href, std::vector<QString> images);

private:
    Ui::Hrefs *ui;
};

#endif // HREFS_H
