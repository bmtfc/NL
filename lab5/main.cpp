#include "functions.h"

int main()
{
    const auto dd = 4;
    double precision = 1e-3;
    auto **AArray = new double*[dd];
    for (auto i = 0; i < dd; ++i)
        AArray[i] = new double[dd];
    auto *BArray = new double[dd];
    cout << "Coefficients ?" << endl;
    cout << "1 - Custom" << endl;
    cout << "0 - Default" << endl;
    bool newValueEntered;
    while (cout << "Your choice: " && !(cin >> newValueEntered))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input; please re-enter.\n";
    }
    int dimensionCount;
    if (newValueEntered)
    {
        cout << "Enter new dimension: ";
        cin >> dimensionCount;
        cout << "Enter new coefficients: " << endl;
        for (auto i = 0; i < dimensionCount; ++i)
        {
            for (auto j = 0; j < dimensionCount; ++j)
            {
                cin >> AArray[i][j];
            }
            cin >> BArray[i];
        }
        cout << "Enter precision: ";
        cin >> precision;
    }
    else
    {
        fillWithDefaultJacobi(AArray, BArray);
        dimensionCount = 4;
    }
    cout << "\nHere is your matrix: " << endl;
    printFullArrayJacobi(AArray, BArray);
    cout << "Jacobi method" << endl;
    int jI = jacobiMethod(AArray, BArray, precision);
    for (int i= 0; i < dd; ++i)
    {
        delete[] AArray[i];
    }
    delete[] AArray;
    delete[] BArray;
    const int ddd = 4;
    AArray = new double*[ddd];
    for (auto i = 0; i < ddd; ++i)
        AArray[i] = new double[ddd];
    BArray = new double[ddd];
    if (!newValueEntered)
    {
        fillWithDefaultSeidel(AArray, BArray);
        dimensionCount = 4;
    }
    cout << "\nYour matrix: " << endl;
    printFullArraySeidel(AArray, BArray);
    cout << "Seidel method" << endl;
    int sI = seidelMethod(AArray, BArray, precision);
    for (int i = 0; i < ddd; ++i)
    {
        delete[] AArray[i];
    }
    delete[] AArray;
    delete[] BArray;
    cout << endl;
    if ( jI > sI)
        cout << "Jacobi takes more iterations" << endl;
    else
        cout << "Seidel takes more iterations" << endl;
    return 0;
}
