#include <iostream>
#include <vector>

class Interface
{
public:
    virtual ~Interface() = default;

    virtual void do_job() const = 0; //никогда не вызывается сам по себе, называется abstract
};

class Employee: public Interface
{
public:
    Employee(const std::string &name)
        : name_(name)
    {

    }
    virtual ~Employee()
    {
        std::cout << name_ << " employee destruction" << std::endl;
    }

    void do_job() const override
    {
        std::cout << "employee job of " << name_ << std::endl;
    }
protected:
    std::string name_;
};

class Manager: public Employee
{
public:
    Manager(const std::string &name)
        : Employee(name)
    {

    }
    ~Manager() override
    {
        std::cout << name_ << " manager destruction" << std::endl;
    }
    void do_job() const override
    {
        std::cout << "manager job of " << name_ << std::endl;
    }

};

int main()
{
    std::vector <Interface*> employees;
    employees.push_back(new Employee("Dan"));
    employees.push_back(new Employee("Vasya"));
    employees.push_back(new Manager("Alice"));
    for (size_t i = 0; i < employees.size(); ++i)
    {
        employees[i]->do_job();
    }
    for (Interface* e: employees)
    {
        delete e;
    }
    return 0;
}
