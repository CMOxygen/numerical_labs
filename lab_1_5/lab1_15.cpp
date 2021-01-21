#include <iostream>

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
    int equatioNum = 0;

    double detA;

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

    double C[size + 1]; 

    double x[size];

    double inv_A[size][size] = {
        {7.5, 1.8, -2.1, -7.7},
        {-10.0, 1.3, -20.0, -1.4},
        {2.8, -1.7, 3.9, 4.8},
        {10.0, 31.4, -2.1, -10.0}};

    double inv_A2[size][size] = {
        {7.5, 1.8, -2.1, -7.7},
        {-10.0, 1.3, -20.0, -1.4},
        {2.8, -1.7, 3.9, 4.8},
        {10.0, 31.4, -2.1, -10.0}};

    double dbgA[size][size] = {
        {7.5, 1.8, -2.1, -7.7},
        {-10.0, 1.3, -20.0, -1.4},
        {2.8, -1.7, 3.9, 4.8},
        {10.0, 31.4, -2.1, -10.0}};

    //1. Решить систему [A]x=B методом Гаусса

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

    for (int i = equatioNum + 1; i < size; i++) //ЭТАП ПРЯМОГО ХОДА. ПРИВОДИМ МАТРИЦУ К ВЕРХНЕ-ТРЕУГОЛЬНОМУ ВИДУ.
    {                                                
        for (int j = 0; j < size + 1; j++)
        {
            C[j] = AB[equatioNum][j] / AB[equatioNum][equatioNum]; 

            AB[i][j] = AB[i][j] - C[j] * AB[i][equatioNum]; 
        }
        if (i == size - 1)
        {
            equatioNum++;
            i = equatioNum;
        }
    }

    std::cout << "Matritsa v verhne-treugol'nom registre" << std::endl;

    for (int i = 0; i < size; i++) //ВЫВОДИМ ПОЛУЧЕННУЮ МАТРИЦУ НА ЭКРАН
    {
        for (int j = 0; j < size + 1; j++)
        {
            std::cout << AB[i][j];
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    //ЭТАП ОБРАТНОГО ХОДА. ПОЛУЧАЕМ КОРНИ ИЗ ПОЛУЧИВШЕЙСЯ МАТРИЦЫ. 
    float Xn = AB[size - 1][size] / AB[size - 1][size - 1]; 
    x[size - 1] = Xn;                                         

    float Bnn;
    float Ann_n;
    float Ann_nn;
    float Xnn;

    for (equatioNum = 1; equatioNum <= size; equatioNum++) 
    {
        Bnn = AB[size - equatioNum - 1][size];
        Ann_n = AB[size - equatioNum - 1][size - 1];
        Ann_nn = AB[size - equatioNum - 1][size - equatioNum - 1];

        Xnn = (Bnn - Ann_n * Xn) / Ann_nn;
        x[size - equatioNum - 1] = Xnn;
        Xn = Xnn;
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

    equatioNum = 0;
    detA = 1;

 

    for (int i = equatioNum + 1; i < size; i++)   //ВЫЧИСЛЯЕМ ДЕТЕРМИНАНТ
    {
        for (int j = 0; j < size; j++)
        {
            C[j] = A[equatioNum][j] / A[equatioNum][equatioNum];

            A[i][j] = A[i][j] - C[j] * A[i][equatioNum];

            if (i == j)
                detA *= A[i][j]; 
        }

        if (i == size - 1)
        {
            equatioNum++;
            i = equatioNum;
        }
    }
    std::cout << "Matrix in triangle view" << std::endl;

    for (int i = 0; i < size; i++) //ВЫВОДИМ МАТРИЦУ В ВЕРХНЕ=ТРУГОЛЬНОМ ВИДЕ
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << A[i][j];
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Determinant A" << std::endl;
    std::cout << detA << std::endl; //ВЫВОДИМ ДЕТЕРМИНАНТ


    system("pause");
}
