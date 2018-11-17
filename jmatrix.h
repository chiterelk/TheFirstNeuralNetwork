#ifndef JMATRIX_H
#define JMATRIX_H

#include <QVector>
#include <QString>

class JMatrix
{
public:
    JMatrix(int m,int n);
    JMatrix();
    int getM(void){ return m; };
    int getN(void){ return n; };
    QVector<double> &operator [] (int m);
    static void print(JMatrix matrix,QString name);
    static JMatrix transponir(JMatrix matrix);
    static JMatrix multiplication(JMatrix a,JMatrix b);
    void printSize();
    static JMatrix sigmoida(JMatrix x);
    static JMatrix sigmoida_dx(JMatrix x);
private:
    QVector <QVector <double>> matrix;
    int n;
    int m;
    static double sigm(double x);

};

#endif // JMATRIX_H
