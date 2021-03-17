#include "some_of_four.h"

void Some_of_four::input(QFile& file)
{
    QTextStream ifs(&file);
    this->question = ifs.readLine();
    for (size_t i = 0; i < 4; i++)
    {
        this->answers[i] = ifs.readLine();
    }
    size_t count{ifs.read(4).toULongLong()};
    for(size_t i = 0; i < count; i++)
    {
        this->correct_answer[i] = ifs.read(4).toULongLong();
    }
}
