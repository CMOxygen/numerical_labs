#include <iostream>
#include <vector>
#include <math.h>

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
    int counter = 0;

    float AB[size][size + 1] = {{3.8, 6.7, -1.2, 5.2},
                                {6.4, 1.3, -2.7, 3.8},
                                {2.4, -4.5, 3.5, -0.6}};

    float itViewAB[size][size + 1] = {{3.8, 6.7, -1.2, 5.2},
                                      {6.4, 1.3, -2.7, 3.8},
                                      {2.4, -4.5, 3.5, -0.6}};

    float temp[size + 1];
    float tempVal;
    float sols[size];

    float convA[size][size + 1] = {{3.8, 6.7, -1.2, 5.2},
                                   {6.4, 1.3, -2.7, 3.8},
                                   {2.4, -4.5, 3.5, -0.6}};

    float E = 0.0001;

    cout << "Ishodnaya matritsa" << endl;

    for (int i = 0; i < size; i++) //ВЫВОД ИСХОДНОЙ МАТРИЦЫ
    {
        for (int j = 0; j < size + 1; j++)
        {
            cout << AB[i][j];
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < size; i++) //ПРИВЕДЕНИЕ МАТРИЦЫ К ВИДУ УДОБНОМУ ДЛЯ ИТЕРАЦИЙ
    {
        for (int j = 0; j < size + 1; j++)
        {
            if (j < size)
            {
                itViewAB[i][j] = itViewAB[i][j] / AB[i][i];
            }
            else
            {
                itViewAB[i][j] = itViewAB[i][j] / AB[i][i];
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size + 1; j++)
        {
            cout << itViewAB[i][j];
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < size; i++) //ВЫНОСИМ Х ЗА =
    {
        for (int j = 0; j < size; j++)
        {
            if (itViewAB[i][j] == 1)
            {
                tempVal = itViewAB[i][0];
                itViewAB[i][0] = 1;
                itViewAB[i][j] = tempVal;
            }
        }

        tempVal = itViewAB[i][1];
        itViewAB[i][1] = itViewAB[i][size];
        itViewAB[i][size] = tempVal;

        for (int j = 2; j < size + 1; j++)
        {

            itViewAB[i][j] = -itViewAB[i][j];
        }
    }

    cout << "Iteratsionniy vid" << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size + 1; j++)
        {
            cout << itViewAB[i][j];
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < size; i++) //НАХОДИМ Х ИЗ УРАВНЕНИЙ, И ЗАПИСЫВАЕМ В МАССИВ SOLS
    {
        sols[i] = 0;

        for (int j = 0; j < size + 1; j++)
        {

            sols[i] += itViewAB[i][j];
        }
    }
    cout << "Resheniya uravneniy" << endl;

    for (int j = 0; j < size; j++)
    {
        cout << sols[j];
        cout << " ";
    }

    cout << endl;
    cout << endl;

    float maxVal;
    int maxCell;

    for (int i = 0; i < size; i++) //ПРИВОДИМ СИСТЕМУ УРАВНЕНИЙ К СХОДЯЩЕМУСЯ ВИДУ
    {

        maxVal = 0;

        for (int j = 0; j < size + 1; j++)
        {

            if (AB[i][j] > maxVal)
            {

                maxVal = convA[i][j];
                maxCell = j;
            }
        }

        tempVal = convA[i][i];
        convA[i][i] = maxVal;
        convA[i][maxCell] = tempVal;
    }

    cout << "Shodyashiysya vid:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size + 1; j++)
        {
            cout << convA[i][j];
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    float norm;
    float c;
    float delta;

    for (int k = 0; k < 4; k++) //РЕШАЕМ СИСТЕМУ МЕТОДОМ ЗЕЙДЕЛЯ
    {
        norm = 0;

        for (int i = 0; i < size; i++)
        {
            c = convA[i][size - 1];

            for (int j = 0; j < size; j++)
            {
                if (i != j)
                {
                    c = c - convA[i][j] * sols[size - i - 1];
                }
            }
            delta = sols[size - i - 1] - c;

            if (delta > norm)
            {
                norm = delta;
            }
            sols[size - i - 1] = c;
        }
        if (norm < E)
            break;
    }

    cout << "Resheniya s priblizheniyem 0.0001" << endl;

    for (int j = 0; j < size; j++)
    {
        cout << sols[j];
        cout << " ";
    }
    cout << endl;
}
