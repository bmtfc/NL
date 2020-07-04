//
// Created by Mac on 26.04.2020.
//

#include "functions.h"

#define SIZE 2
//------------------------------------------------------------------------------------
void SimpleIterarionMethod(double(*func1)(double arg1), double(*func2)(double arg2), double results[SIZE])
{
    int iAmountOfIterations = 0;
    double writeInResult[SIZE];
    printf("Введіть початкове наближення x0 та y0: \n");
    scanf("%lf %lf", &writeInResult[0], &writeInResult[1]);

    while (true)
    {
        iAmountOfIterations++;
        results[1] = Yfunc1(writeInResult[0]); // y=
        results[0] = Xfunc2(writeInResult[1]); // x=
        //|X*-Xn|+|Y*-Yn| (Оцінка похибки за формулою < eps )
        if (((results[0] - writeInResult[0]) && (results[1] - writeInResult[1])) < EPS)
            break;
        //Наступне наближення
        writeInResult[0] = results[0];
        writeInResult[1] = results[1];
        //printf("Ітерації = %d\n X= %.2lf, y = %.2lf\n", iAmountOfIterations,writeInResult[0],writeInResult[1]);
    }
    printf("Число ітерацій = %d\n", iAmountOfIterations);

}
//------------------------------------------------------------------------------------
void NewtonsMethod(double results[SIZE])
{
    printf("Введіть початкове наближення x0 та y0: \n");
    scanf("%lf %lf", &results[0], &results[1]);

    int iter = 0;
    double x = results[0], y = results[1];

    //Cума модулів визначників Якобіан.
    while (fabs(det_x(x, y)) + fabs(det_y(x, y)) > EPS)
    {
        x = x + det_x(x, y);
        y = y + det_y(x, y);
        iter++;
    }

    results[0] = x;
    results[1] = y;
    printf("Число ітерацій = %d\n", iter);
}
//------------------------------------------------------------------------------------.
double f1(double x, double y)
{
    return cos(x - 1) + y - 0.5;
}

double f2(double x, double y)
{
    return x - cos(y) - 3;
}

double f1_x(double x)
{
    return -sin(x - 1);
}

double f1_y()
{
    return 1;
}

double f2_x()
{
    return 1;
}

double f2_y(double y)
{
    return sin(y);
}
//Поправка Х
double det_x(double x, double y)
{
    return (f2(x, y) * f1_y() - f1(x, y) * f2_y(y)) / (f1_x(x) * f2_y(y) - f1_y() * f2_x());
}
//Поправка Y
double det_y(double x, double y)
{
    return (f2_x() * f1(x, y) - f1_x(x) * f2(x, y)) / (f1_x(x) * f2_y(y) - f1_y() * f2_x());
}

double Yfunc1(double x)
{
    return 0.5 - cos(x - 1);
}

double Xfunc2(double y)
{
    return 3 + cos(y);
}
