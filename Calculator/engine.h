#pragma once
#include <QString>
#include <QStringList>

class Interaction
{
public:
    virtual ~Interaction() = default;

    int sum(int first_value, int second_value);

    int subtraction(int first_value, int second_value);

    int calculate_expression(QString expression);

    QStringList tokenize(QString expression);
private:
//int first_value;
//int second_value;
};
