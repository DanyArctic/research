#include "engine.h"
#include <QStringList>

int Interaction::sum(int first_value, int second_value)
{
    return first_value + second_value;
}

int Interaction::subtraction(int first_value, int second_value)
{
    return first_value - second_value;
}

QStringList Interaction::tokenize(QString expression)
{
    QStringList tokens;
    tokens.append("");
    for (QChar c: expression)
    {
        if (c.isDigit())
        {
            tokens.back().append(c);
        }
        else
        {
            QString token{c};
            tokens.append(token);
            tokens.append("");
        }
    }
    return tokens;
    //добавить поддержку скобок
}

int Interaction::calculate_expression(QString expression)
{
    QStringList tokens = tokenize(expression);
    //где-то тут желательно написать польскую запись (в отдельной ф-ии), а цикл ниже переписать с учётом этого и выделить в новую ф-цию подсчёта
    int val_1;
    val_1 = tokens[0].toInt();
    for (int i = 1; i < tokens.size(); i += 2)
    {
        int val_2 = tokens[i+1].toInt();
        if (tokens[i] == "+")
        {
            val_1 = sum(val_1, val_2);
        }
        else if (tokens[i] == "-")
        {
            val_1 = subtraction(val_1, val_2);
        }
    }
    return val_1;
}
