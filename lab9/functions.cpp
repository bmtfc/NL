//
// Created by Mac on 20.05.2020.
//

#include "functions.h"
#include <cmath>

//--------------------------------------------------------------------------------
//Наближення за методом найменших квадратів
double *dblAproximation(const double *x, const double *y, const int k, int n) {
    auto a = new double *[n + 1];
    for (int i = 0; i <= n; ++i)
        a[i] = new double[n + 1];
    auto b = new double[n + 1];
    auto res = new double[n + 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            double sum = 0;
            if (i == 0 && j == 0)
                //k=6
                a[i][j] = k;
            else {
                //k(0,m)
                for (int q = 0; q < k; ++q) {
                    //Cуми Xів
                    //(Xi)^j+k
                    sum += pow(x[q], i + j);
                }
                //1. N1 = 6 (Xi)
                //2. N2 = 0,15 + 0,20 + 0,25 + 0,30 + 0,40 + 0,50 = 1.800 (Xi^2)
                //3. N3 = 0,15^2 + 0,20^2 + 0,25^2 + 0,30^2 + 0,40^2 +0,50^2 = 0,625 (Xi^3)
                //4. N4 = 0,243 (Xi^4)
                a[i][j] = sum;
            }
        }
        double sum = 0;
        for (int q = 0; q < k; ++q) {   //Cуми Уів
            //Yi*(Xi)^k
            sum += y[q] * ((i == 0) ? 1 : pow(x[q], i));
        }
        b[i] = sum;
    }
    cout << "\nМатриця коефіцієнтів:" << endl;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j)
            printf("% .3lf", a[i][j]);
        printf(" ->% .3lf\n", b[i]);
    }
    GaussMethod(n + 1, a, b, res);
    for (int i = 0; i <= n; ++i)
        delete a[i];
    delete[] a;
    delete[] b;
    return res;
}

//--------------------------------------------------------------------------------
void GaussMethod(const int n, double **a, const double *b, double *xValue) {
    double coef = 0, temp, max;
    auto aTmp = new double *[n];
    auto bTmp = new double[n];
    auto x = new double[n];
    for (int i = 0; i < n; i++)
        aTmp[i] = new double[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            aTmp[i][j] = a[i][j];
        bTmp[i] = b[i];
    }
    //Визначення максимального
    for (int mc, mk = 0; mk < n; mk++) {
        max = aTmp[mk][mk];
        mc = mk;
        for (int i = 0; i < n; i++) {
            if (i < mk)
                continue;
            else if (aTmp[i][mk] > fabs(max)) {
                max = aTmp[i][mk];
                //Крок де найбільший елемент шоб поміняти місцями
                mc = i;
            }
        }
        if (max != aTmp[mk][mk]) {
            //Міняєм рядки місцями
            for (int j = 0; j < n; j++) {
                temp = aTmp[mc][j];
                aTmp[mc][j] = aTmp[mk][j];
                aTmp[mk][j] = temp;
            }
            temp = bTmp[mc];
            bTmp[mc] = bTmp[mk];
            bTmp[mk] = temp;
        }
        for (int i = 0; i < n; i++) {
            if ((i < mk) || (mk == 0))
                continue;
            else {
                //Занулення під головною діагоналлю
                double tmp = aTmp[i][mk - 1] / aTmp[mk - 1][mk - 1];
                for (int j = 0; j < n; j++) {
                    if (j < mk)
                        aTmp[i][j] = 0;
                    else {
                        aTmp[i][j] = aTmp[i][j] - aTmp[i - 1][j] * tmp;
                    }
                }
                bTmp[i] = bTmp[i] - bTmp[i - 1] * tmp;
            }
        }
    }
    //Рахуєм з кінця
    for (int i = n - 1; i >= 0; i--) {
        x[i] = (bTmp[i] - coef) / aTmp[i][i];
        if (i == 0)
            break;
        else
            coef += x[i] * aTmp[i - 1][i];
    }
    for (int i = 0; i < n; i++)
        xValue[i] = x[i];
    for (int i = 0; i < n; i++)
        delete aTmp[i];
    delete[] aTmp;
    delete[] bTmp;
    delete[] x;
}
