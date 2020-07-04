#include "functions.hpp"

int main()
{
    int i,j;
    const int dd = 3; //default size of the array
    auto **AArray = new double*[dd];
    for ( i = 0; i < dd; ++i)
        AArray[i] = new double[dd];
    auto *BArray = new double[dd];
    cout << "Values :" << endl;
    cout << "0 - Default" << endl;
    cout << "1 - Custom" << endl;
    bool newValueEntered = false;
    while (cout << "So, your choice: " && !(cin >> newValueEntered))
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
        cout << "Enter new coefs.: " << endl;
        for (i = 0; i < dimensionCount; ++i)
        {
            for (j = 0; j < dimensionCount; ++j)
            {
                cin >> AArray[i][j];
            }
        }
        cout << "Enter new results: " << endl;
        for (i = 0; i < dimensionCount; ++i)
        {
            cin >> BArray[i];
        }
    }
    else
    {
        fillWithDefault(AArray, BArray);
        dimensionCount = 3;
    }
    cout << "\n Your matrix: " << endl;
    printFullArray(AArray, BArray);
    cout << "\n Gaussian method :" << endl;
    GaussianMethod(AArray, BArray, dimensionCount);
    cout << "\n LU method :" << endl;
    LUMethod(AArray, BArray, dimensionCount);
    return 0;
}

