#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //    W12[0][0] = -1;
    //    W12[0][1] = 2;
    //    W12[1][0] = 1;
    //    W12[1][1] = 1;
    //    W12[2][0] = 3;
    //    W12[2][1] = -2;

    //    W23[0][0] = 1;
    //    W23[0][1] = 2;
    //    W23[0][2] = 4;

    //    perceptron.setW12(W12);
    //    perceptron.setW23(W23);

    x[0][0] = 0;
    x[0][1] = 0;
    x[1][0] = 0;
    x[1][1] = 1;
    x[2][0] = 1;
    x[2][1] = 0;
    x[3][0] = 1;
    x[3][1] = 1;

    y0[0][0] = 0;
    y0[1][0] = 1;
    y0[2][0] = 1;
    y0[3][0] = 0;
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked()
{
    for( int epoh = 0;epoh<1000;epoh++)
    {


        for(int i =0;i<y0.getM();i++)
        {
            qDebug()<<perceptron.interrogation(x[i])[0][0];
            perceptron.learning(y0[i][0],perceptron.interrogation(x[i])[0][0]);
        }
    }

}
