#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
virtual void keyPressEvent(QKeyEvent * pEvent);

public slots:

private slots:
    void digitClicked();

    void clearClicked();

    void equalClicked();

private:
    Ui::MainWindow *ui;
};
