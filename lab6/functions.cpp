//
// Created by Mac on 10.04.2020.
//

#include "functions.h"

void printArray(double **array, const int &dimension) {
    for (auto i = 0; i < dimension; ++i) {
        for (auto j = 0; j < dimension; ++j) {
            cout << setprecision(4) << setw(7) << showpos << array[i][j] << " ";
        }
        cout << "| " << setprecision(4) << setw(7) << showpos << array[i][3] << endl;
    }
    cout << endl;
}

void printFullArray(double **array, double *res, const int &rows, const int &cols) {
    for (auto i = 0; i < rows; ++i) {
        for (auto j = 0; j < cols; ++j) {
            cout << setprecision(4) << setw(7) << showpos << array[i][j] << " ";
        }
        cout << "| " << setprecision(4) << setw(7) << showpos << res[i] << endl;
    }
    cout << endl;
}

void squaresMethod(double **array, double *res, const int &rowsCount, const int &colsCount, double **matrixN,
                   double *matrixC) {
    double **transposed = new double *[colsCount];
    double **N = new double *[colsCount];
    double *C = new double[colsCount];
    for (int i = 0; i < colsCount; i++) {
        transposed[i] = new double[rowsCount];
        N[i] = new double[colsCount];
    }

    for (int i = 0; i < rowsCount; i++) {
        for (int j = 0; j < colsCount; j++) {
            transposed[j][i] = array[i][j];
        }
    }
    for (int i = 0; i < colsCount; i++) {
        double sum2 = 0;
        for (int j = 0; j < colsCount; j++) {
            double sum = 0;
            sum2 = 0;
            for (int k = 0; k < rowsCount; k++) {
                sum += transposed[i][k] * array[k][j];
                sum2 += transposed[i][k] * res[k];
            }
            N[i][j] = sum;
        }
        C[i] = sum2;
    }
    printFullArray(N, C, colsCount, colsCount);

    for (int i = 0; i < 3; i++) {
        matrixC[i] = C[i];
        for (int j = 0; j < 3; j++)
            matrixN[i][j] = N[i][j];
    }
    for (int i = 0; i < colsCount; ++i) {
        delete[] transposed[i];
        delete N[i];
    }
    delete[] transposed;
    delete[] N;
    delete[] C;
}


void inverseMatrix(double array[3][3]) {
    double array2[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            array2[i][j] = findMinor(array, i, j);
            if ((i + j) % 2) {
                array2[i][j] = -array2[i][j];
            }
        }
    }
    copyArray(array2, array);
}

void transpose(double array[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i < j) {
                double temp = array[i][j];
                array[i][j] = array[j][i];
                array[j][i] = temp;
            }
        }
    }
}

void multiplyArray(double array[3][3], double multVal) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            array[i][j] *= multVal;
        }
    }
}

double findDeterminant(double arr[3][3]) {
    double det = 0;
    det += arr[0][0] * arr[1][1] * arr[2][2];
    det += arr[0][1] * arr[1][2] * arr[2][0];
    det += arr[1][0] * arr[2][1] * arr[0][2];
    det -= arr[0][2] * arr[1][1] * arr[2][0];
    det -= arr[0][0] * arr[1][2] * arr[2][1];
    det -= arr[0][1] * arr[1][0] * arr[2][2];
    return det;
}

double findMinor(double array[3][3], int i0, int j0) {
    double min[4];
    double minor;
    int z = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i != i0 && j != j0) {
                min[z] = array[i][j];
                z++;
            }
        }
    }
    minor = min[0] * min[3] - min[1] * min[2];
    return minor;
}

void copyArray(double array1[3][3], double array2[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            array2[i][j] = array1[i][j];
        }
    }
}


void squaremethod(double **matrixN, double *matrixC) {
    int i, j;
    double L[3][3], Lt[3][3];

    L[0][0] = sqrt(matrixN[0][0]);

    for (j = 1; j < 3; j++)
        L[0][j] = matrixN[0][j] / L[0][0];

    for (i = 1; i < 3; i++)
        for (j = 0; j < 3; j++) {

            if (i == j) {
                double sum1 = 0;
                for (int k = 0; k < i; k++)
                    sum1 += (L[k][i]) * (L[k][i]);
                L[i][j] = sqrt(matrixN[i][j] - sum1);
            }

            if (i < j) {
                double sum2 = 0;
                for (int k = 0; k < i; k++)
                    sum2 += (L[k][i]) * (L[k][j]);
                L[i][j] = (matrixN[i][j] - sum2) / L[i][i];
            }

            if (i > j)
                L[i][j] = 0;
        }


    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            Lt[i][j] = L[i][j];

    transpose(Lt);

    double Y[3], X[3];
    double tempL = 1.0 / findDeterminant(L);
    double tempLt = 1.0 / findDeterminant(Lt);
    inverseMatrix(L);
    transpose(L);
    multiplyArray(L, tempL);


    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            Y[i] = L[i][j] * matrixC[j];

    inverseMatrix(Lt);
    transpose(Lt);
    multiplyArray(Lt, tempLt);


    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            X[i] = Lt[i][j] * Y[j];


    cout << setprecision(10)<< "x1 = " << X[0] << "\t";
    cout << "x2 = " << X[1] << "\t";
    cout << "x3 = " << X[2] << "\t";

}