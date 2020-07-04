#include <iostream>
#define SIZE 10
using namespace std;
int Factorial(int n);
double Lagrange(const double *dblArrX, double *dblArrY, double dblX);
double Newton(const double *dblArrX, const double *dblArrY, double dblX);


int main()
{
    double dblArrX[SIZE] = { 0.101, 0.106, 0.111,0.116, 0.121,0.126,0.131,0.136,0.141,0.146 };
    double dblArrY[SIZE] = { 1.261, 1.276, 1.291,1.306, 1.321,1.336,1.352,1.367,1.383,1.399 };


    double x0 = 0.1102;
    cout<<"|"<<dblArrX[0]<<"|"<<dblArrX[1]<<"|"<<dblArrX[2]<<"|"<<dblArrX[3]<<"|"<<dblArrX[4]<<"|"<<dblArrX[5]<<"|"<<dblArrX[6]<<"|"<<dblArrX[7]<<"|"<<dblArrX[8]<<"|"<<dblArrX[9]<<"|"<<endl;
    cout<<"|"<<dblArrY[0]<<"|"<<dblArrY[1]<<"|"<<dblArrY[2]<<"|"<<dblArrY[3]<<"|"<<dblArrY[4]<<"|"<<dblArrY[5]<<"|"<<dblArrY[6]<<"|"<<dblArrY[7]<<"|"<<dblArrY[8]<<"|"<<dblArrY[9]<<"|"<<endl;
    cout<<endl;
    cout << "-----------------------------------|" << endl;
    cout << "Lagrange = " << Lagrange(dblArrX, dblArrY, x0) << endl;
    cout << "-----------------------------------|" << endl;
    cout << "Newton = " << Newton(dblArrX, dblArrY, x0) << endl;
    cout << "-----------------------------------|" << endl;

    return 0;
}
double Lagrange(const double *dblArrX, double *dblArrY, double dblX)
{
    double sum = 0;
    for (int i = 0; i < SIZE; i++) {
        //i=j, 1
        double dobutok = 1;
        for (int j = 0; j < SIZE; j++) {
            //Pi(Xj)=0, i != j;
            if (i != j) {
                //Pi(X)=(X-X0)/(Xi-X0)
                dobutok *= (dblX - dblArrX[j]) / (dblArrX[i] - dblArrX[j]);//Li(x)-коефіцієнти Лагранжа
            }
        }
        //Інтерполяційний поліном лагранжа
        //Ln(x)=Li(x)*Yi
        sum += dobutok * dblArrY[i];
    }
    return sum;
}
double Newton(const double *dblArrX, const double *dblArrY, double dblX)
{
    //X1-X0
    //h- крок інтерполяції
    double h = dblArrX[1] - dblArrX[0];
    //f(X0)
    double fx = dblArrY[0];
    //Масив під значення Y-ків.
    double deltay[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        //Переписуєм значення Y
        deltay[i][0] = dblArrY[i];
    }

    for (int i = 1; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE - i; j++)
        {
            //∆f(Xi)=f(Xi+1)-f(Xi)
            deltay[j][i] = deltay[j + 1][i - 1] - deltay[j][i - 1];
        }
    }
    for (int i = 1; i < SIZE; i++)
    {
        //∆f(X0)
        double chuselnuk = deltay[0][i];
        //n!
        double znamennuk = Factorial(i), term = 0;

        for (int j = 0; j < i; j++)
        {
            //∆f(X0) * (X-X0)
            chuselnuk *= dblX - dblArrX[j];
            //n!h (1!h, 2!h і тд...)
            znamennuk *= h;
        }
        //Інтерполяційна формула для рівновіддалених вузлів
        //∆f(X0) * (X-X0)/ 1!h і тд...
        term = chuselnuk / znamennuk;
        //Pn(x)=f(X0) + ....
        fx += term;
    }
    return fx;
}
int Factorial(int n)
{
    int result = n;
    for (int i = 1; i < n; i++)
    {
        result *= i;
    }
    return result;
}