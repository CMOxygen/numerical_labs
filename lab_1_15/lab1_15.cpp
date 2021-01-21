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
    const int matrixSize = 4;
    int equatioNum = 0;

    float detA;

    float A[matrixSize][matrixSize] = {
        {7.5, 1.8, -2.1, -7.7},
        {-10.0, 1.3, -20.0, -1.4},
        {2.8, -1.7, 3.9, 4.8},
        {10.0, 31.4, -2.1, -10.0}};

    float B[matrixSize] = {
        1.1,
        1.5,
        1.2,
        -1.1};

    float AB[matrixSize][matrixSize + 1] = {
        {7.5, 1.8, -2.1, -7.7, 1.1},
        {-10.0, 1.3, -20.0, -1.4, 1.5},
        {2.8, -1.7, 3.9, 4.8, 1.2},
        {10.0, 31.4, -2.1, -10.0, -1.1}};

    float C[matrixSize + 1]; // = { , , , , };

    float equatinSolutions[matrixSize];

    float inv_A[matrixSize][matrixSize] = {
        {7.5, 1.8, -2.1, -7.7},
        {-10.0, 1.3, -20.0, -1.4},
        {2.8, -1.7, 3.9, 4.8},
        {10.0, 31.4, -2.1, -10.0}};

    float inv_A2[matrixSize][matrixSize] = {
        {7.5, 1.8, -2.1, -7.7},
        {-10.0, 1.3, -20.0, -1.4},
        {2.8, -1.7, 3.9, 4.8},
        {10.0, 31.4, -2.1, -10.0}};

    float dbgA[matrixSize][matrixSize] = {
        {7.5, 1.8, -2.1, -7.7},
        {-10.0, 1.3, -20.0, -1.4},
        {2.8, -1.7, 3.9, 4.8},
        {10.0, 31.4, -2.1, -10.0}};

    //1. Решить систему [A]x=B методом Гаусса

    //ВЫВОДИМ ИСХОДНУЮ МАТРИЦУ НА ЭКРАН

    std::cout << "Zadanie 1" << std::endl;
    std::cout << "Ishodnaya matritsa A+B" << std::endl;

    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize + 1; j++)
        {
            std::cout << AB[i][j];
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl;

    for (int i = equatioNum + 1; i < matrixSize; i++) //ЭТАП ПРЯМОГО ХОДА. ПРИВОДИМ МАТРИЦУ К ВЕРХНЕ-ТРЕУГОЛЬНОМУ ВИДУ.
    {                                                 //ПРИВЕДЕНИЕ ПРОИСХОДИТ В ДВУХ ЦИКЛАХ FOR
        for (int j = 0; j < matrixSize + 1; j++)
        {
            C[j] = AB[equatioNum][j] / AB[equatioNum][equatioNum]; //В ДАННОЙ ЧАСТИ КОДА ВЫЧИСЛЯЕТСЯ СТРОКА, КОТОРАЯ БУДЕТ ВЫЧИТАТЬСЯ ИЗ ОСТАЛЬНЫХ УРАВНЕНИЙ

            AB[i][j] = AB[i][j] - C[j] * AB[i][equatioNum]; //ЗДЕСЬ ПРОИСХОДИТ УМНОЖЕНИЕ ЭТОЙ СТРОКИ, ЗАТЕМ ДАННАЯ СТРОКА ВЫЧИТАЕТСЯ ИЗ ОСТАЛЬНЫХ УРАВНЕНИЙ
        }

        if (i == matrixSize - 1)
        {
            equatioNum++;
            i = equatioNum;
        }
    }

    std::cout << "Matritsa v verhne-treugol'nom registre" << std::endl;

    for (int i = 0; i < matrixSize; i++) //ВЫВОДИМ ПОЛУЧЕННУЮ МАТРИЦУ НА ЭКРАН
    {
        for (int j = 0; j < matrixSize + 1; j++)
        {
            std::cout << AB[i][j];
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    //ЭТАП ОБРАТНОГО ХОДА. ПОЛУЧАЕМ КОРНИ ИЗ ПОЛУЧИВШЕЙСЯ МАТРИЦЫ. НАЙДЕННЫЕ КОРНИ ЗАНОСЯТСЯ В МАССИВ

    float Xn = AB[matrixSize - 1][matrixSize] / AB[matrixSize - 1][matrixSize - 1]; //ЗАДАЕМ Xn ДЛЯ ПОСЛЕДУЮЩИХ ВЫЧИСЛЕНИЙ
    equatinSolutions[matrixSize - 1] = Xn;                                          //И ЗАПЕСЫВАЕМ ЕГО В МАССИВ РЕШЕНИЙ УРАВНЕНИЯ

    float Bnn;
    float Ann_n;
    float Ann_nn;
    float Xnn;

    for (equatioNum = 1; equatioNum <= matrixSize; equatioNum++) //НАХОДИМ ОСТАЛЬНЫЕ РЕШЕНИЯ УРАВНЕНИЯ, И ЗАПИСЫВАЕМ ИХ В МАССИВ РЕШЕНИЙ
    {
        Bnn = AB[matrixSize - equatioNum - 1][matrixSize];
        Ann_n = AB[matrixSize - equatioNum - 1][matrixSize - 1];
        Ann_nn = AB[matrixSize - equatioNum - 1][matrixSize - equatioNum - 1];

        Xnn = (Bnn - Ann_n * Xn) / Ann_nn;
        equatinSolutions[matrixSize - equatioNum - 1] = Xnn;
        Xn = Xnn;
    }

    std::cout << std::endl;
    std::cout << "Resheniya uravneniya:" << std::endl;

    for (int i = 0; i < 4; i++) //ВЫВОДИМ МАССИВ РЕШЕНИЙ НА ЭКРАН
    {
        std::cout << "X";
        std::cout << i + 1;
        std::cout << " ";
        std::cout << equatinSolutions[i] << std::endl;
    }
    std::cout << std::endl;

    //2. Найти детерминант матрицы [A]

    std::cout << "Zadanie 2" << std::endl;

    equatioNum = 0;
    detA = 1;

    //ДЛЯ ВЫЧИСЛЕНИЯ ДЕТЕРМИНАНТА, СНАЧАЛА ПЕРЕВОДИМ МАТРИЦУ В ВЕРХНЕ-ТРЕУГОЛЬНЫЙ ВИД, А ЗАТЕМ ПЕРЕМНОЖАЕМ ЭЛЕМЕНТЫ ДИАГОНАЛИ.

    for (int i = equatioNum + 1; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            C[j] = A[equatioNum][j] / A[equatioNum][equatioNum]; //В ДАННОЙ ЧАСТИ КОДА ВЫЧИСЛЯЕТСЯ СТРОКА, КОТОРАЯ БУДЕТ ВЫЧИТАТЬСЯ ИЗ ОСТАЛЬНЫХ УРАВНЕНИЙ

            A[i][j] = A[i][j] - C[j] * A[i][equatioNum]; //ЗДЕСЬ ПРОИСХОДИТ УМНОЖЕНИЕ ЭТОЙ СТРОКИ, ЗАТЕМ ДАННАЯ СТРОКА ВЫЧИТАЕТСЯ ИЗ ОСТАЛЬНЫХ УРАВНЕНИЙ

            if (i == j)
                detA *= A[i][j]; //ЗДЕСЬ ПРОИСХОДИТ ПЕРЕМНОЖЕНИЕ ДИАГОНАЛИ
        }

        if (i == matrixSize - 1)
        {
            equatioNum++;
            i = equatioNum;
        }
    }
    std::cout << "Matritsa v verhne-treugil'nom vide" << std::endl;

    for (int i = 0; i < matrixSize; i++) //ВЫВОДИМ МАТРИЦУ В ВЕРХНЕ=ТРУГОЛЬНОМ ВИДЕ
    {
        for (int j = 0; j < matrixSize; j++)
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
