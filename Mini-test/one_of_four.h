#ifndef ONE_OF_FOUR_H
#define ONE_OF_FOUR_H

#include "question_base.h"

#include <array>

class One_of_four : public Question_base
{
public:
    One_of_four();

private:
    std::array<QString> answers;
    int correct_answer;
};

#endif // ONE_OF_FOUR_H
