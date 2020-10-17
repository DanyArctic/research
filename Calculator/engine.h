#pragma once
#include <QString>
#include <QStringList>
#include <QDebug>

class Interaction
{
public:
    virtual ~Interaction() = default;

    int sum(int first_value, int second_value);

    int subtraction(int first_value, int second_value);

    int calculate_expression(QString expression);

    QStringList tokenize(QString expression);

    QStringList postfix_notation(QString tokens);
private:
    bool has_lower_priority(QString left, QString right);
//int first_value;
//int second_value;
};
