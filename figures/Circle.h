//
// Created by daniel on 26.08.2020.
//
#pragma once
#include "Figure.h"

class Circle : public Figure {
public:
    Circle(double value);

    bool has_height() override;

    bool has_lenght() override;

    bool has_diametr() override;

    void set_diameter(double value);

    void set_radius(double value);

    double get_diameter();

    double get_perimeter() override;

    double get_radius();

private:
    double diameter_;
    double radius_;
};