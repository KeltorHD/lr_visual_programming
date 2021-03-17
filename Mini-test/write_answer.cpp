#include "write_answer.h"

void Write_answer::input(QFile &file)
{
    QTextStream ifs(&file);
    this->question = ifs.readLine();
    this->correct_answer = ifs.readLine();
}
