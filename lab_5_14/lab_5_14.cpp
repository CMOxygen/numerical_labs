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
    double Pl = 0;
    double Pn = 0;
    double temp;
    double fact;

    double xy[2][size] = {{0.180, 0.185, 0.190, 0.195, 0.200, 0.205},
                          {5.61543, 5.46693, 5.32634, 5.19304, 5.06649, 4.94619}};

    double delY[size][size];

    double h = xy[0][1] - xy[0][0];

    cout.precision(6);

    cout << "Basic matrix" << endl;

    for (int i = 0; i < 2; i++) //ВЫВОДИМ ИСХОДНУЮ МАТРИЦУ
    {
        for (int j = 0; j < size; j++)
        {
            cout << fixed << xy[i][j];
            cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < size; i++) //МНОГОЧЛЕН ЛАГРАНЖА
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
        Pl += xy[1][i] * top / bot;
    }
    cout << "Lagrange solution" << endl;
    cout << Pl << endl; //ВЫВОДИМ РЕЗУЛЬТАТ

    //ФОРМУЛА ЭЙЛЕРА
    for (int i = 0; i < size; i++) //СЧИТАЕМ ДЕЛЬТА Y
    {
        for (int j = 0; j < size; j++)
        {
            if (i == 0)
            {
                delY[i][j] = xy[1][j + 1] - xy[1][j];
            }
            else
            {
                delY[i][j] = delY[i - 1][j + 1] - delY[i - 1][j];
            }
        }
    }

    for (int i = 0; i < size; i++) //ВЫЧИСЛЯЕМ ОТВЕТ
    {
        temp = 1;
        fact = 1;

        for (int j = 0; j <= i; j++)
        {
            temp *= x - xy[0][j];

            if (j > 0)
            {
                fact *= j;
            }
        }
        Pn += xy[1][0] + temp * delY[0][i] / (fact + h); //ВЫВОДИМ РЕЗУЛЬТАТ РЕШЕНИЯ
    }
    cout << endl;
    cout << "Euler solution" << endl;
    cout << fixed << Pn << endl;

    system("pause");
}