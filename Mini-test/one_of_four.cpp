#include "one_of_four.h"

void One_of_four::input(QFile& file)
{
    QTextStream ifs(&file);
    this->question = ifs.readLine();
    for (size_t i = 0; i < 4; i++)
    {
        this->answers[i] = ifs.readLine();
    }
    this->correct_answer = ifs.readLine().toInt();
}
