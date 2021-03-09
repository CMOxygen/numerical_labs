#include <iostream>
#include <iomanip>

/*
Вариант 1.15
1. Решить систему [A]x=B методом Гаусса
                                       
       7.5   1.8  -2.1  -7.7        1.1
  A =-10.0   1.3 -20.0  -1.4  B =   1.5
       2.8  -1.7   3.9   4.8        1.2
      10.0  31.4  -2.1 -10.0       -1.1
* 2. Найти детерминант матрицы [A]
* 3. Найти обратную матрицу для матрицы [A]
*/

int main()
{
    const int size = 4;
    int num = 0;

    double detA = 1;
    double c = 0;

    double A[size][size] = {
        {7.5, 1.8, -2.1, -7.7},
        {-10.0, 1.3, -20.0, -1.4},
        {2.8, -1.7, 3.9, 4.8},
        {10.0, 31.4, -2.1, -10.0}};

    double B[size] = {
        1.1,
        1.5,
        1.2,
        -1.1};

    double AB[size][size + 1] = {
        {7.5, 1.8, -2.1, -7.7, 1.1},
        {-10.0, 1.3, -20.0, -1.4, 1.5},
        {2.8, -1.7, 3.9, 4.8, 1.2},
        {10.0, 31.4, -2.1, -10.0, -1.1}};

    double x[size];

    double a[size][size] = {
        {7.5, 1.8, -2.1, -7.7},
        {-10.0, 1.3, -20.0, -1.4},
        {2.8, -1.7, 3.9, 4.8},
        {10.0, 31.4, -2.1, -10.0}};

    double invA[size][size];

    std::cout.precision(6);

    //ВЫВОДИМ ИСХОДНУЮ МАТРИЦУ НА ЭКРАН

    std::cout << "Basic matrix" << std::endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size + 1; j++)
        {
            std::cout << AB[i][j];
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    //ЭТАП ПРЯМОГО ХОДА. ПРИВОДИМ МАТРИЦУ К ВЕРХНЕ-ТРЕУГОЛЬНОМУ ВИДУ.

    for (int k = 0; k < size; k++)
    {
        for (int i = k + 1; i < size; i++)
        {
            c = A[i][k] / A[k][k];
            B[i] = B[i] - c * B[k];
            for (int j = k + 1; j < size; j++)
            {
                A[i][k] = 0;
                A[i][j] = A[i][j] - c * A[k][j];
            }
        }
    }
    std::cout << "Matrix in triangle mode" << std::endl;

    //ВЫВОДИМ ПОЛУЧЕННУЮ МАТРИЦУ НА ЭКРАН

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j == 3)
            {
                std::cout << A[i][j];
                std::cout << "  ";
                std::cout << B[i] << std::endl;
            }
            else
            {
                std::cout << A[i][j];
                std::cout << "  ";
            }
        }
    }

    //ЭТАП ОБРАТНОГО ХОДА. ПОЛУЧАЕМ КОРНИ ИЗ ПОЛУЧИВШЕЙСЯ МАТРИЦЫ.

    x[3] = B[3] / A[3][3];

    for (int i = 2; i > -1; i--)
    {
        c = B[i];
        for (int j = i + 1; j < 4; j++)
        {
            c = c - A[i][j] * x[j];
        }
        x[i] = c / A[i][i];
    }
    std::cout << std::endl;
    std::cout << "Equation solution" << std::endl;

    for (int i = 0; i < 4; i++) //ВЫВОДИМ МАССИВ РЕШЕНИЙ НА ЭКРАН
    {
        std::cout << "X";
        std::cout << i + 1;
        std::cout << " ";
        std::cout << x[i] << std::endl;
    }
    std::cout << std::endl;

    num = 0;

    //ВЫЧИСЛЯЕМ ДЕТЕРМИНАНТ

    for (int i = 0; i < size; i++)
    {
        detA *= A[i][i];
    }
    std::cout << "Determinant A" << std::endl;
    std::cout << detA << std::endl; //ВЫВОДИМ ДЕТЕРМИНАНТ

    //3. Найти обратную матрицу для матрицы [A]

    for (int col = 0; col < size; col++)
    {
        std::cout << std::endl;
        std::cout << "Column ";
        std::cout << col + 1;
        std::cout << " of the inverted matrix" << std::endl;

        std::cout << "Starting equation:" << std::endl; //ВЫВОД НАЧАЛЬНОЙ МАТРИЦЫ

        for (int i = 0; i < size; i++)
        {
            if (i == col)
            {
                B[i] = 1;
            }
            else
            {
                B[i] = 0;
            }
            for (int j = 0; j < size; j++)
            {
                A[i][j] = a[i][j];

                std::cout << std::fixed << A[i][j];
                std::cout << "        ";
            }
            std::cout << std::endl;
        }
        for (int s = 0; s < size; s++)
        {
            for (int i = s + 1; i < size; i++)
            {
                c = A[i][s] / A[s][s];
                B[i] = B[i] - c * B[s];

                for (int j = s + 1; j < size; j++)
                {
                    A[i][s] = 0;
                    A[i][j] = A[i][j] - c * A[s][j];
                }
            }
        }
        std::cout << std::endl;

        x[3] = B[3] / A[3][3];

        for (int i = 2; i > -1; i--)
        {
            c = B[i];

            for (int j = i + 1; j < size; j++)
            {
                c = c - A[i][j] * x[j];
            }
            x[i] = c / A[i][i];
        }
        std::cout << "Solutions:" << std::endl;

        for (int i = 0; i < 4; i++)
        {
            std::cout << "x";
            std::cout << i + 1;
            std::cout << " = ";
            std::cout << x[i];
            std::cout << std::endl;
        }
        std::cout << std::endl;

        for (int i = 0; i < size; i++)
        {
            invA[i][col] = x[i];
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << invA[i][j];
            std::cout << "     ";
        }
        std::cout << std::endl;
    }
    system("pause");
}