#include "jmatrix.h"
#include <QDebug>

JMatrix::JMatrix(int m, int n)
{
    if((m>0)&&(n>0))
    {
        JMatrix::m = m;
        JMatrix::n = n;
        for(int i = 0; i<m;i++)
        {
            QVector<double> tempVector;
            for(int j = 0; j<n;j++)
            {
                tempVector.push_back(0);
            }
            matrix.push_back(tempVector);
        }
    }else{
        qDebug()<<"Недопустимый размер матрицы!";
    }

}

JMatrix::JMatrix()
{
    JMatrix::m = 1;
    JMatrix::n = 1;
    for(int i = 0; i<m;i++)
    {
        QVector<double> tempVector;
        for(int j = 0; j<n;j++)
        {
            tempVector.push_back(0);
        }
        matrix.push_back(tempVector);
    }
}

QVector<double> &JMatrix::operator [](int m)
{
    return matrix[m];
}

void JMatrix::print(JMatrix matrix, QString name)
{
    for(int m = 0;m<matrix.getM();m++)
        for(int n = 0; n<matrix.getN();n++)
            qDebug()<<name + "("+QString::number(m)+","+QString::number(n)+")="+ QString::number(matrix[m][n]);
}

JMatrix JMatrix::transponir(JMatrix matrix)
{
    JMatrix temp(matrix.getN(),matrix.getM());
    for(int m = 0; m<matrix.getM();m++)
        for(int n = 0;n<matrix.getN();n++)
            temp[n][m] = matrix[m][n];
    return temp;
}

JMatrix JMatrix::multiplication(JMatrix a, JMatrix b)
{
    if(a.getN() == b.getM())
    {
        JMatrix c(a.getM(),b.getN());

        for (int m = 0; m < a.getM(); ++m)
            for (int n = 0; n < b.getN(); ++n)
            {
                double sum = 0;
                for (int k = 0; k < b.getM(); ++k)
                    sum += a[m][k] * b[k][n];
                c[m][n] = sum;
            }
        return c;
    }else{
        qDebug()<<"Матрици не подходят для умножения!";
        return JMatrix();
    }

}

void JMatrix::printSize()
{
    qDebug()<<QString::number(m)+"x"+QString::number(n);
}

JMatrix JMatrix::sigmoida(JMatrix x)
{
    for(int m = 0; m<x.getM();m++)
        for(int n = 0;n<x.getN();n++)
            x[m][n] = JMatrix::sigm(x[m][n]);
    return x;
}

JMatrix JMatrix::sigmoida_dx(JMatrix x)
{
    for(int m = 0; m<x.getM();m++)
        for(int n = 0;n<x.getN();n++)
            x[m][n] = JMatrix::sigm(x[m][n])*(1-JMatrix::sigm(x[m][n]));
    return x;
}

double JMatrix::sigm(double x)
{
    return 1/(1+exp(-x));
}
