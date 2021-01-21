#include <iostream>
#include <math.h>
#include <iomanip>

// Вариант 6.6
// 1) Вычислить интеграл по формуле Симпсона при n = 8; оценить
// погрешность результата, составив таблицу конечных разностей.
// 	1.2
// 	⌠ sin(2x)
// 	│ ─────── dx
// 	⌡    x*x
// 	0.8

using namespace std;

int main()
{

    const int n = 8;
    const int n2 = 2 * 8;

    double a = 1.2;
    double b = 0.8;
    double h = (1.2 - 0.8) / n; //0.025
    double h2 = (1.2 - 0.8) / n2;

    double I = 0;
    double I2 = 0;
    double tmp = 0;

    double y[n];

    double y2[n2];
    double x;

    cout.precision(6);

    cout << "Solution matrix" << endl;

    for (int i = 0; i < n; i++) //ПОЛУЧАЕМ МАССИВ Y
    {
        if (i == 0)
        {
            y[i] = 0;
            x = 0;
        }
        else
        {
            x = i * h;
            y[i] = sin(2 * x) / (x * x);
        }
        cout << x;
        cout << " ";
        cout << y[i] << endl;
    }
    cout << endl;

    tmp += y[0] * y[n - 1];

    for (int i = 0; i < n; i++) //ВЫЧИСЛЯЕМ РЕЗУЛЬТАТ
    {
        if (i % 2 == 0)
        {
            tmp += 2 * y[i];
        }
        else
        {
            tmp += 4 * y[i];
        }
    }

    I = (h / 3) * tmp;

    cout << "Result:" << endl;
    cout << I << endl;
    cout << endl;

    for (int i = 0; i < n2; i++) //ДЛЯ ПРОВЕРКИ ПОГРЕШНОСТИ УВЕЛИЧИВАЕМ ТОЧНОСТЬ
    {
        if (i == 0)
        {
            y2[i] = 0;
            x = 0;
        }
        else
        {
            x = i * h2;
            y2[i] = sin(2 * x) / (x * x);
        }
        cout << x;
        cout << " ";
        cout << y2[i] << endl;
    }
    cout << endl;

    tmp = 0;
    tmp += y2[0] * y2[n2 - 1];

    for (int i = 0; i < n; i++) //РАСЧЕТ ПРИ ПОВЫШЕННОЙ ТОЧНОСТИ
    {
        if (i % 2 == 0)
        {
            tmp += 2 * y2[i];
        }
        else
        {
            tmp += 4 * y2[i];
        }
    }

    I2 = (h2 / 3) * tmp;

    cout << "Result with higher prescision" << endl;
    cout << I2 << endl;

    cout << "Error" << endl;
    cout << I2 - I << endl; //ПОГРЕШНОСТЬ
    
    system("pause");
}