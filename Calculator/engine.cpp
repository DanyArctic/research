#include "engine.h"

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
    //tokens.append("");
    for (QChar c: expression)
    {
        if (c.isDigit())
        {
            if (tokens.isEmpty())
            {
                tokens.append("");
            }
            else if (!tokens.last().isEmpty() && !tokens.last().front().isDigit())
            {
                tokens.append("");
            }
            tokens.back().append(c);
        }
        else
        {
            QString token{c};
            tokens.append(token);
            //tokens.append("");
        }
    }
    return tokens;
    //добавить поддержку скобок
}

QStringList Interaction::postfix_notation(QString tokens)
{
    QStringList tokenized = tokenize(tokens);
    QStringList postfixed, stack;
    if (tokenized.isEmpty()) qDebug() << "error, empty input" << '\n';
    for (QString c: tokenized)
    {
        bool ok;
        c.toInt(&ok, 10);
        if (ok) //проверяем число ли тут, если да, то отправляем в постфикс массив
        {
            postfixed.append(c);
            continue;
        }
        if (c == ")")
        {
            while (stack.last() != "(")
            {
                postfixed.append(stack.takeLast());
            }
            stack.removeLast();
            continue;
        }

        if (stack.empty() || has_lower_priority(c, stack.last())) // || - оператор позволяет не выполнять след. часть, если первая true, && - наоборот
        {
            stack.append(c);
            continue;
        }
        while (!stack.empty() && !has_lower_priority(c, stack.last()))
        {
            postfixed.append(stack.takeLast());
        }
    }
    while (!stack.empty())
    {
        postfixed.append(stack.takeLast());
    }

    qDebug() << "stack: " << stack.join(" ");

    return postfixed;
}

bool Interaction::has_lower_priority(QString left, QString right)
{

    return ((left == "+" && right == "(") ||
            (left == "-" && right == "(") || (left == "*" && right == "-") ||
            (left == "*" && right == "+") || (left == "*" && right == "(") ||
            (left == "/" && right == "") || (left == "/" && right == "-") ||
            (left == "/" && right == "+") || (left == "/" && right == "(") || (left == "("));
}

int Interaction::calculate_expression(QString expression)
{
    QStringList tokens = tokenize(expression);
    //где-то тут желательно написать польскую запись (в отдельной ф-ии), а цикл ниже переписать с учётом этого и выделить в новую ф-цию подсчёта
    int val_1;
    val_1 = tokens[0].toInt();
    for (int i = 0; i < tokens.size(); i += 2)
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
