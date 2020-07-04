#include "functions.h"

int main()
{
    double results1[SIZE];
    double results2[SIZE];
    printf("Наша система:\n");
    printf("cos(x - 1) + y = 0,5\n");
    printf("x - cos(y) = 3\n\n");

    printf("Метод простої ітерації:\n");
    SimpleIterarionMethod(Yfunc1, Xfunc2, results1);
    printf("Результат:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("x = %.2lf\n", results1[i]);
    }

    printf("\nМетод Ньютона:\n");
    NewtonsMethod(results2);
    printf("Результат:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("x = %.2lf\n", results2[i]);
    }
    getchar();
    return 0;
}
