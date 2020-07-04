//
// Created by Mac on 10.04.2020.
//

#ifndef LAB6_FUNCTIONS_H
#define LAB6_FUNCTIONS_H
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void printArray(double **array, const int &dimension);
void printFullArray(double **array, double *res, const int &rows,const int &cols);
void squaresMethod(double **array, double *res, const int &rowsCount, const int &colsCount, double** matrixN, double* matrixC);
void inverseMatrix(double array[3][3]);
void transpose(double array[3][3]);
void multiplyArray(double array[3][3], double multVal);
double findDeterminant(double arr[3][3]);
double findMinor(double array[3][3], int i0, int j0);
void copyArray(double array1[3][3], double array2[3][3]);
void squaremethod(double** matrixN, double* matrixC);

#endif //LAB6_FUNCTIONS_H
