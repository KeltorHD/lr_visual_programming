#include "test.h"

#include <QRandomGenerator>

void Test::init()
{
    QFile file(":/questions.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        throw "not open file";

    QTextStream file_stream(&file);
    size_t count{file.readLine().toULongLong()};


    for (size_t i = 0; i < count; i++)
    {
        int type{file_stream.readLine().toInt()};
        qDebug() << type;
        Question_base* base{};
        switch (type)
        {
        case int(test_type::one_of_four):
            base = new One_of_four;
            break;
        case int(test_type::some_of_four):
            base = new Some_of_four;
            break;
        case int(test_type::write_answer):
            base = new Write_answer;
            break;
        case int(test_type::installation_of_correspondence):
            base = new Installation_of_correspondence;
            break;
        }
        if (base)
        {
            base->input(file_stream);
            base->set_type(test_type(type));
            this->questions[i].first = base;

        }
    }
}

void Test::reset()
{
    this->counter_answers = 0;
    this->current_index = 0;

    for (size_t i = 0; i < 10; i++)
    {
        this->answers[i] = false;
        this->questions[i].second = false;
    }
    std::random_shuffle(this->questions.begin(), this->questions.end());
}

const test_type &Test::get_current_type() const
{
    return this->questions[this->current_index].first->get_type();
}

std::array<QString, 4> Test::get_answers_1() const
{
    One_of_four* q {dynamic_cast<One_of_four*>(this->questions[this->current_index].first)};
    return q->get_answers();
}

std::array<QString, 4> Test::get_answers_2() const
{
    Some_of_four* q {dynamic_cast<Some_of_four*>(this->questions[this->current_index].first)};
    return q->get_answers();
}

std::pair<std::array<QString, 4>, std::array<QString, 4> > Test::get_answers_4() const
{
    Installation_of_correspondence* q {dynamic_cast<Installation_of_correspondence*>(this->questions[this->current_index].first)};
    return q->get_answers();
}
