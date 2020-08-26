#include <iostream>
#include <vector>
#include <random>
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Quadrate.h"

int main()
{
    std::vector<Figure *> figures;
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> figure_type(1, 3);
    std::uniform_int_distribution<int> parameter(1, 40);

    for (int i = 0; i < 20; ++i)
    {
        int random_val = figure_type(generator);
        if (random_val == 1)
        {
            Circle *a = new Circle(parameter(generator));
            figures.push_back(a);
            std::cout << "New circle build:" << '\n' << "Diameter is \t" << a->get_diameter() << std::endl << "Radius is \t\t" << a->get_radius() << std::endl;
        }
        else if (random_val == 2)
        {
            Rectangle *a = new Rectangle(parameter(generator), parameter(generator));
            figures.push_back(a);
            std::cout << "New rectangle build:" << '\n' << "Height is \t" << a->get_height() << "\t Lenght is \t" << a->get_lenght() << std::endl;

        } else
        {
            Quadrate *a = new Quadrate(parameter(generator));
            figures.push_back(a);
            std::cout << "New quadrate build:" << '\n' << "Height is \t" << a->get_height() << "\t Lenght is \t" << a->get_lenght() << std::endl;
        }

        std::cout << "Perimeter is\t" << figures[i]->get_perimeter() << '\n';
        /*
        Circle *c = dynamic_cast<Circle *>(figures[i]);
        if (c)
        {
            std::cout << "Diameter is \t" << c->get_diameter() << std::endl;
        }
        Rectangle *b = dynamic_cast<Rectangle *>(figures[i]);
        if (b)
        {
            std::cout << "Height is \t" << b->get_height() << "\t Lenght is \t" << b->get_lenght() << std::endl;
        }
        Quadrate *f = dynamic_cast<Quadrate *>(figures[i]);
        if (f)
        {
            std::cout << "Height is \t" << f->get_height() << "\t Lenght is \t" << f->get_lenght() << std::endl;
        }
         */
    }
    return 0;
}