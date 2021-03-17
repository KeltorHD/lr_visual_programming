#ifndef WRITE_ANSWER_H
#define WRITE_ANSWER_H

#include "question_base.h"

class Write_answer : public Question_base
{
public:
    Write_answer() = default;

    void input(QFile& file) override;

    const QString& get_correct_answer(){return correct_answer;}

private:
    QString correct_answer;
};

#endif // WRITE_ANSWER_H
