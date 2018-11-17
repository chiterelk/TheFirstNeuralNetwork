#ifndef JPERCEPTRON_H
#define JPERCEPTRON_H

#include <QList>
#include <cmath>

#include "jmatrix.h"

class JPerceptron
{
public:
    JPerceptron(int _inputLayer, int _hiddenLayer, int _outputLayer);
    ~JPerceptron();

    JMatrix interrogation( QVector<double> _input1);
    void learning (JMatrix y0,JMatrix y);
    void learning (double y0, double y);
    double sigmoida(double x);
    void setW12(JMatrix matrix);
    void setW23(JMatrix matrix);
    JMatrix getW12();
    JMatrix getW23();
private:

    int inputLayer_;
    int hiddenLayer_;
    int outputLayer_;

    JMatrix input1_;
    JMatrix W12;
    JMatrix W23;
    JMatrix output2_;
    JMatrix output3_;
    double learningRate = 0.01;



};

#endif // JPERCEPTRON_H
