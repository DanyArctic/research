//
// Created by daniel on 26.08.2020.
//
#pragma once

class Figure {
public:
    virtual ~Figure() = default;

    virtual double get_perimeter() = 0;

    virtual bool has_height() = 0;

    virtual bool has_lenght() = 0;

    virtual bool has_diametr() = 0;
};

