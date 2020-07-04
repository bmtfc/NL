#ifndef functions_hpp
#define functions_hpp

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void fillWithDefault(double **array, double *res);
void printArray(double **array);
void printFullArray(double **array, double *res);
void GaussianMethod(double **A, double *result, int dimension);
void findLU(double **a, double **l, double **u, int n);
void findY(double **array, double **l, double **y, int n);
void findX(double **u, double *y, double *x, int n);
void LUMethod(double **array, double *res, int dimension);



#endif /* functions_hpp */
