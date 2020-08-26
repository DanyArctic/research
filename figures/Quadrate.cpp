//
// Created by daniel on 26.08.2020.
//

#include "Quadrate.h"

Quadrate::Quadrate(int lenght)
        : Rectangle(lenght, lenght)
{}

void Quadrate::set_height(int value)
{
    Rectangle::set_height(value);
    lenght_ = value;
}

void Quadrate::set_lenght(int value)
{
    Rectangle::set_lenght(value);
    height_ = value;
}

double Quadrate::get_perimeter()
{
    int perimeter = lenght_ * 4;
    return perimeter;
}