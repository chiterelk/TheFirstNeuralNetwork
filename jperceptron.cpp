#include "jperceptron.h"
#include <QDebug>
#include <QDateTime>

JPerceptron::JPerceptron(int _inputLayer, int _hiddenLayer, int _outputLayer) :
    input1_(_inputLayer,1),
    W12(_hiddenLayer,_inputLayer),
    W23(_outputLayer,_hiddenLayer),
    output2_(_hiddenLayer,1),
    output3_(_outputLayer,1)


{
    inputLayer_ = _inputLayer;
    hiddenLayer_ = _hiddenLayer;
    outputLayer_ = _outputLayer;

    srand(QDateTime::currentDateTime().toTime_t());

    for(int m = 0; m<W12.getM();m++)
        for(int n = 0; n<W12.getN();n++)
            W12[m][n] = 1 / double(1 + rand()%100);

    for(int m = 0; m<W23.getM();m++)
        for(int n = 0; n<W23.getN();n++)
            W23[m][n] = 1 / double(1 + rand()%100);
}

JPerceptron::~JPerceptron()
{

}


JMatrix JPerceptron::interrogation(QVector<double> _output1)
{
    for(int i = 0;i<_output1.count();i++)
        input1_[i][0] = _output1[i];

    for (int m = 0; m < hiddenLayer_; ++m)
        for (int n = 0; n < 1; ++n) {
        double sum = 0;
            for (int k = 0; k < inputLayer_; ++k)
                sum += W12[m][k] * input1_[k][0];
                output2_[m][n] = sigmoida(sum);
        }


    for (int m = 0; m < outputLayer_; ++m)
        for (int n = 0; n < 1; ++n) {
        double sum = 0;
            for (int k = 0; k < hiddenLayer_; ++k)
                sum += W23[m][k] * output2_[k][n];
                output3_[m][n] = sigmoida(sum);
        }

    return output3_;

}

void JPerceptron::learning(JMatrix y0, JMatrix y)
{
    JMatrix d3(outputLayer_,1);
    for (int m = 0; m < d3.getM(); ++m)
        for (int n = 0; n < d3.getN(); ++n)
            d3[m][n] = (y0[m][n]-y[m][n])*sigmoida(y[m][n])*(1-sigmoida(y[m][n]));
    JMatrix::print(d3,"d3");
    JMatrix d2 = JMatrix::multiplication(JMatrix::transponir(W23),d3);
    for(int m = 0; m<d2.getM();m++)
    {
        d2[m][0] = d2[m][0]*JMatrix::sigmoida_dx(output2_)[m][0];
    }

    for (int m = 0; m < W12.getM(); ++m)
        for (int n = 0; n < W12.getN(); ++n)
        {
            W12[m][n] = W12[m][n] + input1_[n][0]*d2[m][0]*learningRate;
        }


    for (int m = 0; m < W23.getM(); ++m)
        for (int n = 0; n < W23.getN(); ++n)
        {
            W23[m][n] = W23[m][n] + output2_[n][0]*d3[m][0]*learningRate;
        }



}

void JPerceptron::learning(double y0, double y)
{
    JMatrix d3(outputLayer_,1);
            d3[0][0] = (y0-y)*sigmoida(y)*(1-sigmoida(y));
    JMatrix d2 = JMatrix::multiplication(JMatrix::transponir(W23),d3);
    for(int m = 0; m<d2.getM();m++)
    {
        d2[m][0] = d2[m][0]*JMatrix::sigmoida_dx(output2_)[m][0];
    }

    for (int m = 0; m < W12.getM(); ++m)
        for (int n = 0; n < W12.getN(); ++n)
        {
            W12[m][n] = W12[m][n] + input1_[n][0]*d2[m][0]*learningRate;
        }


    for (int m = 0; m < W23.getM(); ++m)
        for (int n = 0; n < W23.getN(); ++n)
        {
            W23[m][n] = W23[m][n] + output2_[n][0]*d3[m][0]*learningRate;
        }

}

double JPerceptron::sigmoida(double x)
{
    return 1/(1+exp(-x));
}

void JPerceptron::setW12(JMatrix matrix)
{
    for (int m = 0; m < W12.getM(); ++m)
        for (int n = 0; n < W12.getN(); ++n)
            W12[m][n] = matrix[m][n];
}

void JPerceptron::setW23(JMatrix matrix)
{
    for (int m = 0; m < W23.getM(); ++m)
        for (int n = 0; n < W23.getN(); ++n)
            W23[m][n] = matrix[m][n];
}

JMatrix JPerceptron::getW12()
{
    return W12;
}

JMatrix JPerceptron::getW23()
{
    return W23;
}


