#ifndef QUESTION_BASE_H
#define QUESTION_BASE_H

#include <QString>
#include <QFile>
#include <QTextStream>

class Question_base
{
public:
    Question_base() = default;
    virtual ~Question_base() = default;

    virtual void input(QFile& file) = 0;

protected:
    QString question;
};

#endif // QUESTION_BASE_H
