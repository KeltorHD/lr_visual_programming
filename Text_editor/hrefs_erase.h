#ifndef HREFS_ERASE_H
#define HREFS_ERASE_H

#include <QDialog>
#include <QTextEdit>

namespace Ui {
class Hrefs_erase;
}

class Hrefs_erase : public QDialog
{
    Q_OBJECT

public:
    explicit Hrefs_erase(QTextEdit* text, QWidget *parent = nullptr);
    ~Hrefs_erase();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::Hrefs_erase *ui;

    QTextEdit* text;
};

#endif // HREFS_ERASE_H
