#include <stdio.h>
#include <math.h>
#include "methods.h"

int main()
{
    int i;
    double a,b;
    double eps;

    printf("\n");
    printf("Use standart values ? 1-yes 0-no ( a=2, b=4, eps=0.01 ) : \n");
    scanf("%d",&i);
    if(i==1)
    {
        a=2;
        b=4;
        eps=0.01;
    }
    else
    {
        printf("Enter a, b and eps :\n");
        scanf("%lf",&a);
        scanf("%lf",&b);
        scanf("%lf",&eps);
    }

    while (a > b)
    {
        printf("Incorrect values. f(a) and f(b) have the same sign. Enter valid a and b : \n");
        scanf("%lf", &a);
        scanf("%lf", &b);
    }
    while (f(a) * f(b) > 0)
    {
        printf("Incorrect values. f(a) and f(b) have the same sign. Enter valid a and b : \n");
        scanf("%lf", &a);
        scanf("%lf", &b);
    }
    while (fabs(a - b) < eps)
    {
        printf("The difference between a and b is less than eps. Enter valid eps :  ");
        scanf("%lf", &eps);
    }

    printf("                X is equall :   Number of iterations:\n");
    method1(a,b,eps);
    method2(a,b,eps);
    method3(a,b,eps);
    method4(a,b,eps);

    return 0;
}