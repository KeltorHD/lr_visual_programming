#ifndef QUESTION_BASE_H
#define QUESTION_BASE_H

#include <QString>
#include <fstream>

class Question_base
{
public:
    Question_base();

    friend std::ifstream& operator>>(std::ifstream& ifs, Question_base* base);

protected:
    QString question;
};

#endif // QUESTION_BASE_H
