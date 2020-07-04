#include  "functions.h"

int main()
{
    int rowsCount = 5, colsCount = 3;
    auto **AArray = new double*[rowsCount];
    for (auto i = 0; i < rowsCount; ++i)
        AArray[i] = new double[colsCount];
    auto *BArray = new double[rowsCount];
    cout << "Coefficients" << endl;
    cout << "1 - Custom" << endl;
    cout << "0 - Default" << endl;
    bool newValueEntered;
    while (cout << "Your choice: " && !(cin >> newValueEntered))
    {
        std::cin.clear();																//clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	//discard input
        std::cout << "Invalid input; please re-enter.\n";
    }
    if (newValueEntered)
    {
        cout << "Enter new dimension: ";
        cin >> rowsCount >> colsCount;
        cout << "Enter new coefficients: " << endl;
        for (auto i = 0; i < rowsCount; ++i)
        {
            for (auto j = 0; j < colsCount; ++j)
            {
                cin >> AArray[i][j];
            }
        }
        cout << "Enter new rvalues: " << endl;
        for (auto i = 0; i < rowsCount; ++i)
        {
            cin >> BArray[i];
        }
    }
    else
    {
        double coeffsArray[5][3] ={ {1,  3, -2},
                                    {3, 4, -5},
                                    {-2,  -5, 3},
                                    {0, 1, -2},
                                    {-2, -3, 2} };
        double coeffsBArray[5] = { 5, 6, -13, 4, 10 };
        for (int i= 0; i <  rowsCount; ++i)
        {
            for (int j=0; j < colsCount; ++j)
            {
                AArray[i][j] = coeffsArray[i][j];
            }
            BArray[i] = coeffsBArray[i];
        }
    }
    cout << "\nYour matrix: " << endl;
    printFullArray(AArray, BArray, rowsCount, colsCount);
    cout << "\nSmallest squares method :" << endl;
    auto** matrixN = new double*[3];
    for(int i = 0;i<3;i++)
        matrixN[i] = new double[3];
    auto* matrixC = new double[3];
    squaresMethod(AArray, BArray, rowsCount, colsCount,matrixN,matrixC);
    squaremethod(matrixN,matrixC);
    for (auto i = 0; i < rowsCount; ++i)
    {
        delete[] AArray[i];
    }
    delete[] AArray;
    delete[] BArray;
    return 0;
}
