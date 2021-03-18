#ifndef SOME_OF_FOUR_H
#define SOME_OF_FOUR_H

#include "question_base.h"

#include <vector>

class Some_of_four : public Question_base
{
public:
    Some_of_four() = default;

    void input(QTextStream& file_stream) override;

    const std::vector<int>& get_correct_answer(){return correct_answer;}
    const std::array<QString, 4>& get_answers(){return answers;}

private:
    std::array<QString, 4> answers;
    std::vector<int> correct_answer;
};

#endif // SOME_OF_FOUR_H
