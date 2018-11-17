#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "jperceptron.h"
#include "jmatrix.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    JPerceptron perceptron = JPerceptron(2,10,1);
    JMatrix etalon = JMatrix(1,1);
    JMatrix x = JMatrix(4,2);
    JMatrix y0 = JMatrix(4,1);
};

#endif // MAINWINDOW_H
