//
// Created by daniel on 26.08.2020.
//

#include "Rectangle.h"

Rectangle::Rectangle(int height, int lenght)
        : height_(height),
          lenght_(lenght)
{}

bool Rectangle::has_height()
{
    return true;
}

bool Rectangle::has_lenght()
{
    return true;
}

bool Rectangle::has_diametr()
{
    return false;
}

void Rectangle::set_lenght(int value)
{
    lenght_ = value;
}

void Rectangle::set_height(int value)
{
    height_ = value;
}

double Rectangle::get_perimeter()
{
int perimeter = height_ * 2 + lenght_ * 2;
return perimeter;
}

int Rectangle::get_height()
{
    return height_;
}

int Rectangle::get_lenght()
{
    return lenght_;
}
