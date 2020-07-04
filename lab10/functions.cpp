//
// Created by Mac on 20.05.2020.
//

#include "functions.h"

#define EPS 1e-3

//Дана функція
double dblMyFunction(double x) {
    return (1 + 2 * x) / pow(log(2 + x * x), 2);
}

//Метод Лівого прямокутника
double dblLeftRectangle(double a, double b, const int N) {
    double sum = 0, k = 0, i = a;
    const double dblStepH = ((b - a) / (double) N);
    while (i < b) {
        k = (dblStepH) * fabs(dblMyFunction(i));
        i += dblStepH;
        sum += k;
    }
    return sum;
}

//Метод Правого прямокутника
double dblRightRectangle(double a, double b, const int N) {
    double sum = 0, k = 0, i = a;
    const double dblStepH = ((b - a) / (double) N);
    while (i < b) {
        k = (dblStepH) * fabs(dblMyFunction(i + dblStepH));
        i += dblStepH;
        sum += k;
    }
    return sum;
}

//Метод середнього прямокутника
double dblMidRectangle(double a, double b, const int N) {
    double sum = 0, k = 0, i = a;
    const double dblStepH = ((b - a) / (double) N);
    while (i < b) {
        k = (dblStepH) * fabs(dblMyFunction((2 * i + dblStepH) / 2.0));
        i += dblStepH;
        sum += k;
    }
    return sum;
}

//Метод трапеції
double dblTrapeze(double a, double b, const int N) {
    double sum = 0, k = 0, i = a;
    const double dblStepH = ((b - a) / (double) N);;
    while (i < b) {
        k = (dblStepH) * (fabs(dblMyFunction(i)) + fabs(dblMyFunction(i + dblStepH))) / 2.0;
        i += dblStepH;
        sum += k;
    }
    return sum;
}

//Метод Сімпосна
double dblSimpsons(double a, double b, const int N) {
    double sum = 0, k = 0, i = a;
    const double step = ((b - a) / (double) N);
    while (i < b) {
        k = (step / 6.0) *
            (fabs(dblMyFunction(i)) + 4 * fabs(dblMyFunction((2 * i + step) / 2.0)) + fabs(dblMyFunction(i + step)));
        i += step;
        sum += k;
    }
    return sum;
}

//--------------------------------------------------------------------------------
double dblIntegralFindN(double a, double b, int *ppvN, double(*Function)(double a, double b, const int N)) {
    *ppvN = 1;
    while (fabs(Function(a, b, *ppvN) - Function(a, b, *ppvN * 2)) > EPS) {
        (*ppvN) *= 2;
    }
    return Function(a, b, *ppvN);
}
