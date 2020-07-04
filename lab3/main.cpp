#include <iostream>
#include "functions.h"

int main()
{

    cout << "1 - Enter custom coefs" << endl;
    cout << "0 - Use standart coefs" << endl;
    bool newValueEntered;
    cin >> newValueEntered;
    double indecesArray[3][3] = { {0.62, 0.56, -0.43},
                                  {1.32, -0.88, 1.76},
                                  {0.73,  1.42, -0.34 }};
    double resultArray[3] = { 1.16, 2.07, 2.18 };
    if (newValueEntered)
    {
        cout << "Enter new coefficients: " << endl;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cin >> indecesArray[i][j];
            }
        }
        cout << "Enter new rvalues: " << endl;
        for (int i = 0; i < 3; ++i)
        {
            cin >> resultArray[i];
        }
    }
    cout << "\nPrint steps ?" << endl;
    cout << "1 - Yes" << endl;
    cout << "0 - No" << endl;
    cin >> newValueEntered;
    cout << "\nHere is yout matrix: " << endl;
    printFullArray(indecesArray, resultArray);
    cout << "Determinant: "<< findDeterminant(indecesArray) << endl;
    cramerMethod(indecesArray,resultArray, newValueEntered);
    matrixMethod(indecesArray, resultArray, newValueEntered);
    return 0;
}



