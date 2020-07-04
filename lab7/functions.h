//
// Created by Mac on 26.04.2020.
//

#ifndef LAB7_FUNCTIONS_H
#define LAB7_FUNCTIONS_H
#define SIZE 2
#define EPS 0.001
#include <cmath>
#include <cstdio>
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS


double Yfunc1(double x);
double Xfunc2(double y);

double f1(double x, double y);

double f2(double x, double y);

double f1_x(double x);

double f1_y();

double f2_x();

double f2_y(double y);

double det_x(double x, double y);

double det_y(double x, double y);

void SimpleIterarionMethod(double(*func1)(double arg1), double(*func2)(double arg2), double results[SIZE]);
void NewtonsMethod(double results[SIZE]);
#endif //LAB7_FUNCTIONS_H
