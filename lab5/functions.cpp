//
// Created by Mac on 10.04.2020.
//

#include "functions.h"


void printArrayJacobi(double *array)
{
    for (auto i = 0; i < 4; ++i)
    {
        cout << setprecision(4) << setw(7) << showpos << array[i] << " " << noshowpos;
    }
    cout << endl;
}

void printArraySeidel(double *array)
{
    for (auto i = 0; i < 4; ++i)
    {
        cout << setprecision(4) << setw(7) << showpos << array[i] << " " << noshowpos;
    }
    cout << endl;
}


void printFullArrayJacobi(double **array, double *res)
{
    for (auto i = 0; i < 4; ++i)
    {
        cout << "x" << i+1 << " = ";
        for (auto j = 0; j < 4; ++j)
        {
            cout << setprecision(2) << setw(6) << showpos << array[i][j] << "x" << noshowpos << j+1 << " " ;
        }
        cout << setprecision(2) << setw(6) << showpos << res[i] << noshowpos << endl;
    }
    cout << endl;
}

void printFullArraySeidel(double** array, double* res)
{
    for (auto i = 0; i < 4; ++i)
    {
        for (auto j = 0; j < 4; ++j)
        {
            cout << setprecision(2) << setw(6) << showpos << array[i][j] << "x" << noshowpos << j+1 << " ";
        }
        cout << setprecision(2) << setw(6) << showpos << " = " << res[i] << noshowpos << endl;
    }
    cout << endl;
}

int jacobiMethod(double** arrayA, double* arrayB, double eps)
{
    const int dd = 4;
    double arrayX[dd], arrayX0[dd];
    for (int i = 0; i < dd; ++i) {
        arrayX[i] = 0;
    }
    int iterationCount = 1;
    do
    {
        for (int i = 0; i < dd; ++i)
        {
            arrayX0[i] = arrayX[i];
        }
        for (int i = 0; i < dd; ++i)
        {
            arrayX[i] = arrayB[i];
            for (int j = 0; j < dd; ++j)
            {
                if (j == i) continue;
                arrayX[i] += arrayA[i][j] * arrayX0[j];
            }
        }
        cout << "Iteration " << iterationCount << " gave a result: " << endl;
        printArrayJacobi(arrayX);
        iterationCount++;
    } while (fabs(arrayX[0] - arrayX0[0]) > (eps));
    return iterationCount;
}

int seidelMethod(double **array, double *res, double eps)
{
    int iterationCount;
    const int dd = 4;
    double arrayX[dd], arrayX0[dd];
    auto **arrayA = new double*[dd];
    for (int i = 0; i < dd; ++i)
    {
        arrayA[i] = new double[dd];
    }
    auto *arrayB = new double[dd];
    for (int i = 0; i < dd; ++i) {
        for (int j = 0; j < dd; ++j)
        {
            if (i == j)
            {
                arrayA[i][i] = 0;
                continue;
            }
            arrayA[i][j] = -array[i][j] / array[i][i];
        }
    }
    for (int i = 0; i < dd; ++i)
    {
        arrayB[i] = res[i] / array[i][i];
    }
    cout << "\nMatrix was normed: " << endl;
    printFullArraySeidel(arrayA, arrayB);
    if (checkForRoots(arrayA,dd)) {
        for (int i = 0; i < dd; ++i)
        {
            arrayX[i] = 0;
        }
        iterationCount = 1;
        do
        {
            for (int i = 0; i < dd; ++i)
            {
                arrayX0[i] = arrayX[i];
            }
            for (int i = 0; i < dd; ++i)
            {
                arrayX[i] = arrayB[i];
                for (int j = 0; j < dd; ++j)
                {
                    if (j == i) continue;
                    arrayX[i] += arrayA[i][j] * arrayX[j];
                }
            }
            cout << "Iteration " << iterationCount << " gave a result: " << endl;
            printArraySeidel(arrayX);
            iterationCount++;
        } while (fabs(arrayX[0] - arrayX0[0]) > (eps));
    }
    else
    {
        cout << "Seidel method couldn`t get a result. Given matrix don`t have a solution." << endl;
    }
    for (int i = 0; i < dd; ++i)
    {
        delete[] arrayA[i];
    }
    delete[] arrayA;
    delete[] arrayB;
    return iterationCount;
}

bool checkForRoots(double** arrayA, int dimension)
{
    double sum;
    for (int i = 0; i < dimension; ++i)
    {
        sum = 0;
        for (int j = 0; j < dimension; ++j)
        {
            sum += arrayA[i][j];
        }
        if (sum > 1)
        {
            return false;
        }
    }
    return true;
}

void fillWithDefaultJacobi(double **array, double *res)
{
    const int dd = 4; //default size
    double def1[dd][dd] = { { 0.19,  -0.12, 0.34, 0.16},
                            {-0.34, 2.08,  -0.17,  0.18},
                            { -0.16,  -0.34, 0.25,  0.31},
                            { -0.12, 0.26,  0.08, 0.32} };
    double def2[dd] = { 0.64, -1.42, 0.42, -0.83 };
    for (auto i = 0; i < dd; ++i)
    {
        for (auto j = 0; j < dd; ++j)
        {
            array[i][j] = def1[i][j];
        }
        res[i] = def2[i];
    }
}

void fillWithDefaultSeidel(double **array, double *res)
{
    const int dd = 4; //default size
    double def1[dd][dd] = { { 0.81,  0.12, -0.34, -0.16},
                            {-0.34, 1.08,  0.17,  -0.18},
                            { 0.16,  0.34, 0.75,  -0.31},
                            { 0.12, -0.26,  -0.08, 0.68} };
    double def2[dd] = { 0.64, -1.42, 0.42, -0.83 };
    for (auto i = 0; i < dd; ++i)
    {
        for (auto j = 0; j < dd; ++j)
        {
            array[i][j] = def1[i][j];
        }
        res[i] = def2[i];
    }
}
