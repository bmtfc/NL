//
// Created by Mac on 10.04.2020.
//

#ifndef LAB5_FUNCTIONS_H
#define LAB5_FUNCTIONS_H
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void fillWithDefaultJacobi(double **array, double *res);
void fillWithDefaultSeidel(double **array, double *res);
void printArrayJacobi(double *array);
void printArraySeidel(double *array);
void printFullArrayJacobi(double **array, double *res);
void printFullArraySeidel(double **array, double *res);
int jacobiMethod(double **arrayA, double *arrayB, double eps);
int seidelMethod(double **arrayA, double *arrayB, double eps);
bool checkForRoots(double **arrayA, int dimension);

#endif //LAB5_FUNCTIONS_H
