#include "test.h"

#include <fstream>

void Test::init()
{
    std::ifstream ifs("questions.txt");
    if (!ifs.is_open())
        throw "not open file";

    size_t count{};
    ifs>>count;

    for (size_t i = 0; i < count; i++)
    {
        int type{};
        ifs>>type;
        Question_base* base{};
        //switch (type)
        //{
        //case test_type::one_of_four:
        //    base = new
        //}
    }
}
