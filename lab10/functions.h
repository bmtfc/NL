//
// Created by Mac on 20.05.2020.
//

#ifndef LAB10_FUNCTIONS_H
#define LAB10_FUNCTIONS_H

#include <cmath>
#include <iostream>

using namespace std;

//--------------------------------------------------------------------------------
double dblMyFunction(double x);

//--------------------------------------------------------------------------------
double dblIntegralFindN(double a, double b, int *N, double(*Function)(double a, double b, const int N));

//--------------------------------------------------------------------------------
double dblLeftRectangle(double a, double b, const int N);

//--------------------------------------------------------------------------------
double dblRightRectangle(double a, double b, const int N);

//--------------------------------------------------------------------------------
double dblMidRectangle(double a, double b, const int N);

//--------------------------------------------------------------------------------
double dblTrapeze(double a, double b, const int N);

//--------------------------------------------------------------------------------
double dblSimpsons(double a, double b, const int N);
//--------------------------------------------------------------------------------


#endif //LAB10_FUNCTIONS_H
