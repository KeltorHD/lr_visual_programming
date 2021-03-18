#ifndef INSTALLATION_OF_CORRESPONDENCE_H
#define INSTALLATION_OF_CORRESPONDENCE_H

#include "question_base.h"

class Installation_of_correspondence : public Question_base
{
public:
    Installation_of_correspondence() = default;

    void input(QTextStream& file_stream) override;

    const std::array<QString, 4>& get_correct_answer(){return correct_answer;}
    const std::array<QString, 4>& get_answers(){return answers;}

private:
    std::array<QString, 4> answers;
    std::array<QString, 4> correct_answer;
};

#endif // INSTALLATION_OF_CORRESPONDENCE_H
