#ifndef TEST_H
#define TEST_H

#include "one_of_four.h"
#include "some_of_four.h"
#include "write_answer.h"
#include "installation_of_correspondence.h"

#include <array>
#include <vector>
#include <QString>
#include <QFile>
#include <QDebug>

class Test
{
public:
    Test() = default;

    /*считывание из файл*/
    void init();

    void reset();

    void set_current_index(size_t index) {this->current_index = index;}

    const size_t& get_counter_answers() const {return counter_answers;}
    const size_t& get_current_index() const {return current_index;}

    const test_type &get_current_type() const;
    const QString& get_question() const {return this->questions[this->current_index].first->get_question();}

    std::array<QString, 4> get_answers_1() const;
    std::array<QString, 4> get_answers_2() const;
    std::pair<std::array<QString, 4>, std::array<QString, 4>> get_answers_4() const;

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
    std::array<bool, 10> answers;
};

#endif // TEST_H
