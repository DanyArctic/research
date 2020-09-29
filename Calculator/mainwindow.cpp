#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <iostream>
#include <QDebug>
#include "engine.h"


MainWindow::MainWindow(QWidget *parent)  //класс - генератор окна
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // connect(ui->HelloButton, &QPushButton::clicked, this, &MainWindow::OnButtonClicked); - это пример
    // соединение сигнала clicked со слотом "OnButtonClicked": чей сигнал, что за сигнал, кто обрабатывает(тут ссылка на себя), слот
    connect(ui->Button_0,SIGNAL(clicked()),this,SLOT(digitClicked()));
    connect(ui->Button_1,SIGNAL(clicked()),this,SLOT(digitClicked()));
    connect(ui->Button_2,SIGNAL(clicked()),this,SLOT(digitClicked()));
    connect(ui->Button_3,SIGNAL(clicked()),this,SLOT(digitClicked()));
    connect(ui->Button_4,SIGNAL(clicked()),this,SLOT(digitClicked()));
    connect(ui->Button_5,SIGNAL(clicked()),this,SLOT(digitClicked()));
    connect(ui->Button_6,SIGNAL(clicked()),this,SLOT(digitClicked()));
    connect(ui->Button_7,SIGNAL(clicked()),this,SLOT(digitClicked()));
    connect(ui->Button_8,SIGNAL(clicked()),this,SLOT(digitClicked()));
    connect(ui->Button_9,SIGNAL(clicked()),this,SLOT(digitClicked()));
    connect(ui->Button_plus,SIGNAL(clicked()),this,SLOT(digitClicked()));
    connect(ui->Button_clear,SIGNAL(clicked()),this,SLOT(clear()));
    connect(ui->Button_equal,SIGNAL(clicked()),this,SLOT(equal()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitClicked()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_label;
    if (ui->calc_screen->text() == "0")
    {
        ui->calc_screen->clear();
    }
    new_label = (ui->calc_screen->text() + button->text());
    ui->calc_screen->setText(new_label);
}

void MainWindow::clear()
{
    ui->calc_screen->clear();
    ui->calc_screen->setText("0");
}

void MainWindow::equal()
{
    digitClicked();
    QString label = ui->calc_screen->text();
    QStringList list = label.split("+");
    QStringList list2 = list[1].split("=");
    QString a = list[0];
    QString b = list2[0];
    Interaction calc;
    ui->calc_screen->setText(QString::number(calc.summary(a.toInt(),b.toInt())));
}
