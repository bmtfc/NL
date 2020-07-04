//
// Created by Mac on 20.05.2020.
//

#ifndef LAB9_FUNCTIONS_H
#define LAB9_FUNCTIONS_H


#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//--------------------------------------------------------------------------------
double *dblAproximation(const double *x, const double *y, const int k, const int n);

//--------------------------------------------------------------------------------
void GaussMethod(const int n, double **a, const double *b, double *rad);


#endif //LAB9_FUNCTIONS_H
