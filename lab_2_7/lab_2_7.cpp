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

    for (int k = 0; k < 3; k++)
    {

        for (int i = 0; i < 3; i++)
        {
            s1 = fabs(A[k][i]);
            for (int j = 0; j < 3; j++)
            {
                s2 = s2 + fabs(A[k][j]);
            }
            if (s1 > s2 - s1)
            {
                for (int j = 0; j < 3; j++)
                {
                    pocket[j] = A[k][j];
                    A[k][j] = A[i][j];
                    A[i][j] = pocket[j];
                }

                pocket[3] = B[k];
                B[k] = B[i];
                B[i] = pocket[3];
            }
            s2 = 0;
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
