#ifndef ONE_OF_FOUR_H
#define ONE_OF_FOUR_H

#include "question_base.h"

#include <array>
#include <QDebug>

class One_of_four : public Question_base
{
public:
    One_of_four() = default;

    void input(QTextStream& file_stream) override;

    int get_correct_answer(){return correct_answer;}
    const std::array<QString, 4>& get_answers(){return answers;}

private:
    std::array<QString, 4> answers;
    int correct_answer;
};

#endif // ONE_OF_FOUR_H
