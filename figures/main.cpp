#include <iostream>
#include <vector>
#include <random>

class Figure {
public:
    virtual ~Figure() = default;

    virtual double get_perimeter() = 0;

    virtual bool has_height() = 0;

    virtual bool has_lenght() = 0;

    virtual bool has_diametr() = 0;

    virtual int get_diameter() = 0;

    virtual int get_height() = 0;

    virtual int get_lenght() = 0;
};

class Circle : public Figure {
public:
    Circle(int value)
            : diameter_(value)
    {}

    bool has_height() override
    {
        return false;
    }

    bool has_lenght() override
    {
        return false;
    }

    bool has_diametr() override
    {
        return true;
    }

    void set_diameter(int value)
    {
        diameter_ = value;
    }

    int get_diameter()
    {
        return diameter_;
    }

    double get_perimeter() override
    {
        return 3.14159265 * diameter_;
    }

    int get_height()
    {
    }

    int get_lenght()
    {
    }

private:
    double diameter_ = 0;
};

class Rectangle : public Figure {
public:
    Rectangle(int value1, int value2)
            : height_(value1),
              lenght_(value2)
    {}

    virtual ~Rectangle() = default;

    bool has_height() override
    {
        return true;
    }

    bool has_lenght() override
    {
        return true;
    }

    bool has_diametr() override
    {
        return false;
    }

    virtual void set_lenght(int value)
    {
        lenght_ = value;
    }

    virtual void set_height(int value)
    {
        height_ = value;
    }

    double get_perimeter() override
    {
        int perimeter = height_ * 2 + lenght_ * 2;
        return perimeter;
    }

    int get_diameter()
    {
    }

    int get_height()
    {
        return height_;
    }

    int get_lenght()
    {
        return lenght_;
    }

protected:
    int height_ = 0;
    int lenght_ = 0;
};

class Quadrate : public Rectangle {
public:
    Quadrate(int value1)
            : Rectangle(value1, value1)
    {}

    void set_height(int value) override
    {
        height_ = value;
        lenght_ = value;
    }

    void set_lenght(int value) override
    {
        lenght_ = value;
        height_ = value;
    }

    double get_perimeter() override
    {
        int perimeter = lenght_ * 4;
        return perimeter;
    }
};

int main()
{
    std::vector<Figure*> figures;
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> figure_type(1, 3);
    std::uniform_int_distribution<int> parameter(1, 40);

    for (int i = 0; i < 20; ++i)
    {
        int random_val = figure_type(generator);
        if (random_val == 1)
        {
            Circle *c = new Circle(parameter(generator));
            figures.push_back(c);
        }
        else if (random_val == 2)
        {
            Rectangle *c = new Rectangle(parameter(generator),parameter(generator));
            figures.push_back(c);

        }
        else
        {
            Quadrate *c = new Quadrate(parameter(generator));
            figures.push_back(c);
        }

        std::cout << "Perimeter is\t" << figures[i]->get_perimeter() << '\n';

        if(figures[i]->has_diametr())
            std::cout << "Diameter is \t" << figures[i]->get_diameter() << std::endl;
        else
            std::cout << "Height is \t" << figures[i]->get_height() << "\t Lenght is \t" << figures[i]->get_lenght() << std::endl;
    }
    return 0;
}