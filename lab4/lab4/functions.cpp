#include "functions.hpp"
#include <vector>

void GaussianMethod(double **array, double *result, int dimension)
{
    double **A = new double*[dimension];
    for (int i = 0; i < dimension; ++i)
    {
        A[i] = new double[dimension + 1];
    }
    for (int i = 0; i < dimension; ++i)
    {
        for (int j = 0; j < dimension+1; ++j)
        {
            if (j!=dimension)
            {
                A[i][j] = array[i][j];
            }
            else
            {
                A[i][j] = result[i];
            }
        }
    }
    for (int i = 0; i < dimension; ++i) //for each column
    {
        double maxEl = fabs(A[i][i]);
        int maxRow = i; //row index
        for (int k = i + 1; k < dimension; ++k) //for each row
        {
            if (fabs(A[k][i]) > maxEl)
            {
                maxEl = fabs(A[k][i]);
                maxRow = k;
            }
        }
        for (int k = i; k < dimension + 1; ++k) //swapping row
        {
            double tempEl = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tempEl;
        }
        for (int k = i + 1; k < dimension; ++k) //a[j] -= a[i]*coefficient
        {
            double c = -A[k][i] / A[i][i];
            for (int j = i; j < dimension + 1; ++j)
            {
                if (i == j) //to avoid error while doing floating point operations
                {
                    A[k][j] = 0.0;
                }
                else
                {
                    A[k][j] += c * A[i][j];
                }
            }
        }
        printArray(A);
    }
    double *x = new double[dimension];
    for (int i = dimension-1; i >= 0; --i )
    {
        x[i] = A[i][dimension] / A[i][i];
        for (int k = i-1; k >= 0; --k)
        {
            A[k][dimension] -= A[k][i] * x[i];
        }
    }
    cout << "Gaussian method gave a result: " << endl;
    for (int i = 0; i < dimension; ++i)
    {
        cout << "x" << noshowpos << i+1 << " = " << setprecision(8) << x[i] << endl;
    }
}

void findLU(double **a, double **l, double **u, int n)
{
    int i = 0, j = 0, k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j < i)
                l[j][i] = 0;
            else
            {
                l[j][i] = a[j][i];
                for (k = 0; k < i; k++)
                {
                    l[j][i] = l[j][i] - l[j][k] * u[k][i];
                }
            }
        }
        for (j = 0; j < n; j++)
        {
            if (j < i)
                u[i][j] = 0;
            else if (j == i)
                u[i][j] = 1;
            else
            {
                u[i][j] = a[i][j] / l[i][i];
                for (k = 0; k < i; k++)
                {
                    u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
                }
            }
        }
    }
}

void findY(double **array, double **l, double *y, int n)
{
    for (int i = 0; i < n; ++i)
    {
        double sum = array[i][n];
        for (int j = 0; j < i; ++j)
            sum -= y[j] * l[i][j];
        y[i] = sum / l[i][i];
    }
}
void findX(double **u, double *y, double *x, int n)
{
    for (int i = n - 1; i >= 0; --i)
    {
        double sum = y[i];
        for (int j = i + 1; j < n; ++j)
            sum -= x[j] * u[i][j];
        x[i] = sum / u[i][i];
    }
}

void LUMethod(double** array, double* res, int dimension)
{
    int i = 0, j = 0 ;
    double **A = new double*[dimension];
    for (i = 0; i < dimension; ++i)
    {
        A[i] = new double[dimension + 1];
    }
    for (i = 0; i < dimension; ++i)
    {
        for (j = 0; j < dimension + 1; ++j)
        {
            if (j != dimension)
            {
                A[i][j] = array[i][j];
            }
            else
            {
                A[i][j] = res[i];
            }
        }
    }
    double **l = new double*[dimension];
    for ( i = 0; i < dimension; ++i)
    {
        l[i] = new double[dimension + 1];
    }
    double **u = new double*[dimension];
    for ( i = 0; i < dimension; ++i)
    {
        u[i] = new double[dimension];
    }
    findLU(array, l, u, dimension);
    cout << "\nL decomposition: " << endl;
    printFullArray(l, res);
    cout << "\nU decomposition: " << endl;
    printFullArray(u, res);
    double *y = new double[dimension];
    double *x = new double[dimension];
    findY(A, l, y, dimension);
    findX(u, y, x, dimension);
    cout << "LU method gave a result: " << endl;
    for (i = 0; i < dimension; ++i)
    {
        cout << "x" << noshowpos << i + 1 << " = " << setprecision(8) << x[i] << endl;
    }
}

void printArray(double **array)
{
    int i = 0, j = 0;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            cout << setprecision(4) << setw(7) << showpos << array[i][j] << " ";
        }
        cout << "| " << setprecision(4) << setw(7) << showpos << array[i][3] << endl;
    }
    cout << endl;
}

void printFullArray(double **array, double *res)
{
    int i = 0, j = 0;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            cout << setprecision(4) << setw(7) << showpos << array[i][j] << " ";
        }
        cout << "| " << setprecision(4) << setw(7) << showpos << res[i] << endl;
    }
    cout << endl;
}

void fillWithDefault(double **array, double *res)
{
    int i = 0, j = 0;
    const int dd = 3; //default size
    double def1[dd][dd] = { {0.62, 0.56, -0.43},
                            {1.32, -0.88, 1.76},
                            {0.73,  1.42, -0.34}};
    double def2[dd] = { 1.16, 2.07, 2.18 };
    for (i = 0; i < dd;++i)
    {
        for (j = 0;j < dd; ++j)
        {
            array[i][j] = def1[i][j];
        }
        res[i] = def2[i];
    }
}
