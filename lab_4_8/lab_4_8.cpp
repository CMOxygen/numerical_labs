#include <iostream>
#include <math.h>

// Вариант 4.8
// 1)  Используя метод Эйлера, получить приближенные значения
// интеграла дифференциального уравнения  y'=f(x,y), удовлетворяющие
// начальным условиям y(0)=0 на отрезке [0,1] с шагом h=0.1.
//
// 		y'=1-sin(x+y)+0.5y/(x+2)

using namespace std;

int main()
{
	double a = 0;
	double b = 1;
	double h = 0.1;

	double n = (b - a) / h;
	double x = a;

	double y[11];
	y[0] = 0;

	cout.precision(6);

	cout << "Start function:" << endl;//ВЫВОДИМ ИСХОДНУЮ ФУНКЦИЮ
	cout << "y'=1-sin(x+y)+0.5y/(x+2)" << endl;

	for (int i = 0; i < n; i++)//ИЩЕМ ЗНАЧЕНИЯ ИНТЕГРАЛА
	{
		y[i + 1] = y[i] + h * (sin(x + y[i]) + 1.5 * y[i] / (x + 2));
		x = x + h;
	}
	cout << "Approximation values of the integral:" << endl;

	for (int i = 0; i < n + 1; i++)//ВЫВОДИМ РЕЗУЛЬТАТ ВЫЧИСЛЕНИЙ
	{
		cout << "x(";
		cout << a;
		cout << ") = ";
		cout << fixed << y[i] << endl;

		a = a + h;
	}

	system("pause");
}