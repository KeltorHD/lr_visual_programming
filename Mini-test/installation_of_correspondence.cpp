#include "installation_of_correspondence.h"

void Installation_of_correspondence::input(QFile &file)
{
    QTextStream ifs(&file);
    this->question = ifs.readLine();
    for (size_t i = 0; i < 4; i++)
    {
        this->answers[i] = ifs.readLine();
    }
    for (size_t i = 0; i < 4; i++)
    {
        this->correct_answer[i] = ifs.readLine();
    }
}
