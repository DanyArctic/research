//
// Created by daniel on 26.08.2020.
//
#pragma once
#include "Figure.h"

class Rectangle : public Figure {
public:
    Rectangle(int height, int lenght);

    virtual ~Rectangle() = default;

    bool has_height() override;

    bool has_lenght() override;

    bool has_diametr() override;

    virtual void set_lenght(int value);

    virtual void set_height(int value);

    double get_perimeter() override;

    int get_height();

    int get_lenght();

protected:
    int height_;
    int lenght_;
};