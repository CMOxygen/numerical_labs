#include <iostream>
#include <math.h>
#include <iomanip>

// Вариант 5.14
//   Найти приближенное значение функции при x = 0.1845 с помощью
// 1) интерполяционного многочлена Лагранжа.
// 2) интерполяционной формулы Ньютона.
//
// x: 0.180   0.185   0.190   0.195   0.200   0.205
// y: 5.61543 5.46693 5.32634 5.19304 5.06649 4.94619

using namespace std;

int main()
{

    const int size = 6;

    double sum = 0;
    double top = 1;
    double bot = 1;
    double x = 0.1845;
    double P = 0;
    double temp;

    double xy[2][size] = {{0.180, 0.185, 0.190, 0.195, 0.200, 0.205},
                          {5.61543, 5.46693, 5.32634, 5.19304, 5.06649, 4.94619}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << xy[i][j];
            cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < size; i++)
    {
        top = 1;
        bot = 1;

        for (int j = 0; j < size; j++)
        {
            if (j != i)
            {
                top *= x - xy[0][j];
                bot *= xy[0][i] - xy[0][j];
            }
        }
        P+=xy[1][i] * top / bot;
    }
    cout << P << endl;

    //system("pause");
}