#include <iostream>
#include <cmath>

using namespace std;

// Дефиниране на функцията f(x)
double f(double x) {
    // Дефиниране на f(x) в зависимост от интервалите
    if (x >= 0 && x <= 0.1)
        return pow(x, 3) + 1; // Функцията в интервала [0, 0.1]
    else if (x > 0.1 && x <= 0.2)
        return 1.001 + 0.03 * (x - 0.1) + 0.3 * pow((x - 0.1), 2); // Функцията в интервала [0.1, 0.2]
    else if (x > 0.2 && x <= 0.3)
        return 1.007 + 0.15 * (x - 0.2) + 0.9 * pow((x - 0.2), 2); // Функцията в интервала [0.2, 0.3]
    else
        return 0; // Връща 0 за стойности извън зададените интервали
}

// Функция за съставната формула на трапеците
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n; // Ширина на всяко подинтервал
    double sum = 0.5 * (f(a) + f(b)); // Добавя половината от първия и последния елемент към сумата

    // Пресмятане на сумата от средните точки на интервалите
    for (int i = 1; i < n; ++i) {
        double x_i = a + i * h; // Средната точка на текущия подинтервал
        sum += f(x_i);
    }

    return h * sum; // Връща приближението на интеграла
}

// Функция за оценка на грешката
double estimate_error(double a, double b, int n) {
    double K = 2.7; // Максимална стойност на втората производна в зададените интервали
    return (K * pow((b - a), 3)) / (12 * pow(n, 2)); // Изчислява и връща оценката на грешката
}

int main() {
    double a = 0.0; // Долна граница на интеграцията
    double b = 0.3; // Горна граница на интеграцията
    int n = 6;      // Брой подинтервали

    double integral = trapezoidal(a, b, n); // Изчислява интеграла
    double error = estimate_error(a, b, n); // Изчислява оценката на грешката

    // Извежда резултата и грешката
    cout << "Integral approx. result: " << integral << endl;
    cout << "Error: " << error << endl;

    return 0;
}
