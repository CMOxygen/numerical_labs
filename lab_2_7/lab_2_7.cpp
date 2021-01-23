#include <iostream>
#include <math.h>
#include <iomanip>

// Вариант 2.7

// 1. Решить систему [A]{x}={B} методом Зейделя с точностью
//    0.0001, приведя ее к виду, удобному для итераций.
//         -                  ¬      -       ¬
//         ¦  3.8   6.7  -1.2 ¦      ¦   5.2 ¦
//     A = ¦  6.4   1.3  -2.7 ¦  B = ¦   3.8 ¦
//         ¦  2.4  -4.5   3.5 ¦      ¦  -0.6 ¦
//         L                  -      L       -

using namespace std;

int main()
{
    const int size = 3;

    double AB[size][size + 1] = {{3.8, 6.7, -1.2, 5.2},
                                 {6.4, 1.3, -2.7, 3.8},
                                 {2.4, -4.5, 3.5, -0.6}};

    double A[size][size] = {{3.8, 6.7, -1.2},
                            {6.4, 1.3, -2.7},
                            {2.4, -4.5, 3.5}};

    double B[size] = {5.2, 3.8, -0.6};

    double pocket[4];
    double x[3];

    double E = 0.0001;
    double norm = 0;
    double del;

    double s1 = 0;
    double s2 = 0;

    double c;

    int i;
    int j;
    int k;
    int d;

    cout.precision(6);

    cout << "Basic matrix: " << endl;

    for (int i = 0; i < size; i++) //ВЫВОД БАЗОВОЙ МАТРИЦЫ
    {
        x[i] = B[i];

        for (int j = 0; j < size; j++)
        {
            if (j == 2)
            {
                cout << fixed << A[i][j];
                cout << "*x";
                cout << fixed << j + 1;
                cout << "      =         ";
                cout << fixed << B[i] << endl;
                cout << " " << endl;
            }

            else
            {
                cout << fixed << A[i][j];
                cout << "*x";
                cout << fixed << j + 1;
                cout << " ";
            }
        }
    }

    double temp = 0;
    double max = 0;
    int cell;

    for (int i = 0; i < size; i++)
    {
        max = 0;
        for (int j = 0; j < size + 1; j++)
        {
            if (AB[i][j] > max)
            {
                max = AB[i][j];
                cell = j;
            }
        }

        temp = AB[i][i];
        AB[i][i] = max;
        AB[i][cell] = temp;
    }

    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size + 1; j++)
    //     {
    //         cout << AB[i][j];
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size + 1; j++)
        {

            if (j < size)
            {
                A[i][j] = AB[i][j];
            }
            else
            {
                B[i] = AB[i][j];
            }
        }
    }

    cout << "Converging view" << endl;

    for (int i = 0; i < size; i++)
    {
        x[i] = B[i];

        for (int j = 0; j < size; j++)
        {
            if (j == 2)
            {
                cout << fixed << A[i][j];
                cout << "*x";
                cout << fixed << j + 1;
                cout << "      =         ";
                cout << fixed << B[i] << endl;
                cout << " " << endl;
            }
            else
            {
                cout << fixed << A[i][j];
                cout << "*x";
                cout << fixed << j + 1;
                cout << " ";
            }
        }
    }

    do //ВЫЧИСЛЯЕМ КОРНИ
    {
        norm = 0;
        for (int i = 0; i < size; i++)
        {
            c = B[i];
            for (int j = 0; j < size; j++)
            {
                if (i != j)
                    c = c - A[i][j] * x[j];
            }

            c = c / A[i][i];
            del = x[i] - c;

            if (del < 0)
            {
                del = del * (-1);
            }
            if (del >= norm)
            {
                norm = del;
            }
            x[i] = c;
        }
        if (norm <= E)
        {
            break;
        }
    } while (true);

    cout << "Solutions: " << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "x";
        cout << fixed << i + 1;
        cout << " = ";
        cout << fixed << x[i] << endl;
    }
    system("pause");
}
