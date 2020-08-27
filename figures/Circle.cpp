//
// Created by daniel on 26.08.2020.
//

#include "Circle.h"

Circle::Circle(double value)
        : diameter_(value),
          radius_(diameter_ / 2.0)
{}

bool Circle::has_height()
{
    return false;
}

bool Circle::has_lenght()
{
    return false;
}

bool Circle::has_diametr()
{
    return true;
}

void Circle::set_diameter(double value)
{
    Circle::set_radius(value / 2.0);
}

void Circle::set_radius(double value)
{
    radius_ = value;
    diameter_ = radius_ * 2.0;
}

double Circle::get_diameter()
{
    return diameter_;
}

double Circle::get_perimeter()
{
    return 3.14159265 * diameter_;
}

double Circle::get_radius()
{
    return radius_;
}