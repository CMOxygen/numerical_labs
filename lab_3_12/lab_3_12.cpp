#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

// Вариант 3.12
// 1) Сделать линейную, квадратичную и кубическую аппроксимацию функции методом наименьших квадратов.
// 2) Посчитать среднеквадратичное отклонение и показать, как оно меняется со степенью аппроксимации.

// x: 1.415   1.420   1.425   1.430   1.435   1.440
// y: 8.88551 8.89599 8.90637 8.91667 8.92687 8.93698

int main()
{
	const int size = 6;

	double x[size] = {1.415, 1.420, 1.425, 1.430, 1.435, 1.440};
	double y[size] = {8.88551, 8.89599, 8.90637, 8.91667, 8.92687, 8.93698};

	double xy[2][size] = {{1.415, 1.420, 1.425, 1.430, 1.435, 1.440},
						  {8.88551, 8.89599, 8.90637, 8.91667, 8.92687, 8.93698}};

	cout.precision(6);

	for (int i = 0; i < size; i++)
	{
		cout << x[i];
		cout << " ";
	}
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		cout << y[i];
		cout << " ";
	}
	cout << endl;

	// ��������� ������

	printf("Starting functions:\n");

	double A[size - 2][size - 2];
	double B[size - 2];
	double xl[4];

	// int i;
	// int j;
	// int n;
	// int k;

	double del;
	double dev;
	double c;

	cout << "x: "; //ВЫВОД ИСХОДНОЙ МАТРИЦЫ

	for (int i = 0; i < 6; i++)
	{
		cout << x[i];
	}
	cout << endl;

	cout << "y: ";

	for (int i = 0; i < 6; i++)
	{
		cout << y[i];
	}
	cout << endl;



	for (int k = 1; k < 4; k++)	//ОСНОВНОЙ АЛГОРИТМ
	{
		for (int i = 0; i <= k; i++)//ПОЛУЧАЕМ МАРИЦЫ A И B
		{
			B[i] = 0;

			for (int n = 0; n < 6; n++)
			{
				B[i] = B[i] + y[n] * pow(x[n], i);
			}
			for (int j = 0; j <= k; j++)
			{
				A[i][j] = 0;
				for (int n = 0; n < 6; n++)
				{
					A[i][j] = A[i][j] + pow(x[n], i + j);
				}
			}
		}

		for (int n = 0; n < k; n++)
		{
			for (int i = n + 1; i <= k; i++)
			{
				c = A[i][n] / A[n][n];
				B[i] = B[i] - (c * B[n]);
				for (int j = n + 1; j <= k; j++)
				{
					A[i][j] = A[i][j] - c * A[n][j];
				}
			}
		}

		xl[k] = B[k] / A[k][k];

		for (int i = k - 1; i > -1; i--)
		{
			c = B[i];

			for (int j = i + 1; j <= k; j++)
			{
				c = c - A[i][j] * xl[j];
			}
			xl[i] = c / A[i][i];
		}		
		cout << "Approximation power ";//ВЫВОДИМ СТЕПЕНЬ АППРОКСИМАЦИ
		cout << k << endl;

		for (int i = 0; i <= k; i++)//ВЫВОДИМ ЗНАЧЕНИЕ АППРОКСИМАЦИИ
		{
			cout << "a(";
			cout << i + 1;
			cout << ") = ";
			cout << xl[i] << endl;
		}

		del = 0;

		for (int i = 0; i < 6; i++) // ВЫЧИСЛЕНИЕ СМЕЩЕНИЯ
		{
			dev = 0;

			for (int j = 0; j <= k; j++)
			{
				dev = dev + xl[j] * pow(x[i], j);
			}
			dev = (dev - y[i]) * (dev - y[i]);
			del = del + dev;
		}
		dev = sqrt(del / 5);

		cout << "Deviation: ";
		cout << fixed << round(dev * 1000000) / 1000000 << endl;
	}
	system("pause");
}