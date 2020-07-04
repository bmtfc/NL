//
// Created by Mac on 17.02.2020.
//

#ifndef TASK_METHODS_H
#define TASK_METHODS_H

#include <stdio.h>
#include <math.h>

double f(double x);
double df(double x);
double d2f(double x);

void method1(double a ,double b ,double eps);
void method2(double a ,double b ,double eps);
void method3(double a ,double b ,double eps);
void method4(double a ,double b ,double eps);

#endif //TASK_METHODS_H
