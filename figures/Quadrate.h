//
// Created by daniel on 26.08.2020.
//
#pragma once
#include "Rectangle.h"

class Quadrate : public Rectangle {
public:
    Quadrate(int lenght);

    void set_height(int value) override;

    void set_lenght(int value) override;

    double get_perimeter() override;
};