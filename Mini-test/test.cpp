#include "test.h"

#include <QRandomGenerator>
#include <algorithm>

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

void Test::check_answer1(size_t answer)
{
    One_of_four* q {dynamic_cast<One_of_four*>(this->questions[this->current_index].first)};
    if (q->get_correct_answer() == answer)
    {
        this->questions[this->current_index].second = true;
    }

    this->answers[this->current_index] = true;
}

void Test::check_answer2(std::vector<int> answers)
{
    Some_of_four* q {dynamic_cast<Some_of_four*>(this->questions[this->current_index].first)};
    try
    {
        for (size_t i = 0; i < std::max(answers.size(), q->get_correct_answer().size()); i++)
        {
            if (answers.at(i) != q->get_correct_answer().at(i))
                throw std::logic_error("");
        }

        this->questions[this->current_index].second = true;
    }
    catch (std::exception& e)
    {

    }

    this->answers[this->current_index] = true;
}

void Test::check_answer3(QString answer)
{
    Write_answer* q {dynamic_cast<Write_answer*>(this->questions[this->current_index].first)};

    if (q->get_correct_answer() == answer.toLower())
        this->questions[this->current_index].second = true;

    this->answers[this->current_index] = true;
}

void Test::check_answer4(std::array<QString, 4> answer)
{
    Installation_of_correspondence* q {dynamic_cast<Installation_of_correspondence*>(this->questions[this->current_index].first)};

    try
    {
        for (size_t i = 0; i < 4; i++)
        {
            if (q->get_correct_answer()[i] != answer[i])
                throw std::logic_error("");
        }

        this->questions[this->current_index].second = true;
    }
    catch (std::exception& e)
    {

    }

    this->answers[this->current_index] = true;
}
