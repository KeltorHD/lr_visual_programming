#include "installation_of_correspondence.h"

void Installation_of_correspondence::input(QTextStream& file_stream)
{
    this->question = file_stream.readLine();
    for (size_t i = 0; i < 4; i++)
    {
        this->answers[i] = file_stream.readLine();
    }
    for (size_t i = 0; i < 4; i++)
    {
        this->correct_answer[i] = file_stream.readLine();
    }
}
