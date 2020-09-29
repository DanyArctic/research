#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "engine.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show(); //показывает окно

    return a.exec(); //запускает event loop (цикл, в котором qt собирает события от ОС, например с клавиатуры)*/

    //Interaction calc;
   // std:: cout << calc.summary(356,5) << std::endl;

    return 0;
}
