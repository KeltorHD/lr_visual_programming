#ifndef TEST_H
#define TEST_H

#include "question_base.h"

#include <array>
#include <vector>
#include <QString>


enum class test_type
{
    one_of_four = 1,
    some_of_four = 2,
    write_answer = 3,
    installation_of_correspondence = 4
};

class Test
{
public:
    Test() = default;

    /*считывание из файл*/
    void init();

    const size_t& get_counter_answers() const {return counter_answers;}

    /*ответ на первый тип*/
    bool check_answer(size_t index, int answer);
    /*ответ на второй тип*/
    bool check_answer(size_t index, std::vector<int> answers);
    /*ответ на третий тип*/
    bool check_answer(size_t index, QString answer);
    /*ответ на четвертый тип*/
    bool check_answer(size_t index, std::vector<QString> answer);

private:
    size_t current_index{0};
    size_t counter_answers{0};
    /*вопрос и его статус: правильно или нет*/
    std::array<std::pair<Question_base*, bool>, 10> questions{};

};

#endif // TEST_H
