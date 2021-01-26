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
    const double pi = 3.14;

    const int n = 8;
    const int n2 = 2 * 8;

    double a = 1.2;
    double b = 0.8;
    double h = (1.2 - 0.8) / n; //0.025
    double h2 = (1.2 - 0.8) / n2;

    double I = 0;
    double I2 = 0;
    double tmp = 0;

    double y[n + 1];

    double y2[n2 + 1];
    double x;

    double deltaY[n + 1][4];

    cout.precision(6);

    cout << "Solution matrix" << endl;

    for (int i = 0; i <= n; i++)
    {
        x = 0;
        x = b + (i * h);
        y[i] = sin((pi / 180) * 2 * x) / (x * x);
        cout << i;
        cout << " ";

        cout << fixed << x;
        cout << " ";
        cout << sin((3.14 / 180) * 2 * x);
        cout << " ";
        cout << x * x;
        cout << " ";
        cout << y[i] << endl;
    }

    cout << endl;

    tmp += y[0] * y[n - 1];

    for (int i = 0; i <= n; i++) //ВЫЧИСЛЯЕМ РЕЗУЛЬТАТ
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

    for (int i = 0; i < 8; i++)
    {

        for (int j = 0; j < n + 1; j++)
        {
            deltaY[i][j] = 0;
        }
    }

    int limit = n;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < limit; j++)
        {
            if (i == 0)
            {
                deltaY[j][i] = y[j + 1] - y[j];
            }
            else
            {
                deltaY[j][i] = deltaY[j + 1][i - 1] - deltaY[j][i - 1];
            }
        }
        limit--;
    }

    for (int i = 0; i < n + 1; i++)
    {
        cout << i;
        cout << " ";

        for (int j = 0; j < 4; j++)
        {

            cout << deltaY[i][j];
            cout << " ";
        }
        cout << endl;
    }

    system("pause");
}