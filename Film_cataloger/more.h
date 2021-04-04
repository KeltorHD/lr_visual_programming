#ifndef MORE_H
#define MORE_H

#include "film.h"
#include <QDialog>

namespace Ui {
class More;
}

class More : public QDialog
{
    Q_OBJECT

public:
    explicit More(QWidget *parent = nullptr);
    ~More();

    void set_film(const Film& Film);

private:
    Ui::More *ui;
};

#endif // MORE_H
