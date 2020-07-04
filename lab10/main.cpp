#include "functions.h"
#include <iomanip>

int main() {
    const double dblLeftBorder = 0, dblRightBorder = 4;
    int iFirstStep = 1;
    cout << "Функцiя: 1+2x/ln^2(2+x^2)" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Крайнє ліве значення = " << dblLeftBorder << endl << "Крайнє праве значення = " << dblRightBorder << endl;
    cout << "----------------------------------------------" << endl;
    cout << "\nМетод правого прямокутника:  y = "
         << dblIntegralFindN(dblLeftBorder, dblRightBorder, &iFirstStep, dblRightRectangle) << "\nКрок(N) = "
         << setprecision(5) << iFirstStep << endl;
    cout << "----------------------------------------------" << endl;
    cout << "\nМетод лівого прямокутника:   y = "
         << dblIntegralFindN(dblLeftBorder, dblRightBorder, &iFirstStep, dblLeftRectangle) << "\nКрок(N) = "
         << setprecision(5) << iFirstStep << endl;
    cout << "----------------------------------------------" << endl;
    cout << "\nМетод середнього прямокутника: y = "
         << dblIntegralFindN(dblLeftBorder, dblRightBorder, &iFirstStep, dblMidRectangle) << "\nКрок(N)= "
         << setprecision(5) << iFirstStep << endl;
    cout << "----------------------------------------------" << endl;
    cout << "\nМетод трапеції:           y = "
         << dblIntegralFindN(dblLeftBorder, dblRightBorder, &iFirstStep, dblTrapeze) << "\nКрок(N) = "
         << setprecision(5) << iFirstStep << endl;
    cout << "----------------------------------------------" << endl;
    cout << "\nМетод сімпсона:           y = "
         << dblIntegralFindN(dblLeftBorder, dblRightBorder, &iFirstStep, dblSimpsons) << "\nКрок(N) = "
         << setprecision(5) << iFirstStep << endl;
    cout << "----------------------------------------------" << endl;
    return 0;
}
