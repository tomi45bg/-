#include <iostream>
#include <cmath>

using namespace std;

// Функция за интегриране
double func(double x) {
    return x * log(x);
}

// Съставна квадратурна формула на трапеците
double trapezoidal_rule(int n, double a, double b) {
    double h = (b - a) / n;
    double sum = 0.5 * (func(a) + func(b)); // Събираме краищата на интервала

    // Добавяме средните точки
    for (int i = 1; i < n; i++) {
        double xi = a + i * h;
        sum += func(xi);
    }

    return h * sum;
}

int main() {
    int n = 5; // брой трапеци
    double a = 1.0; // начало на интервала
    double b = 2.0; // край на интервала

    // Извикваме функцията за съставната квадратурна формула на трапеците
    double result = trapezoidal_rule(n, a, b);

    // Отпечатваме резултата
    cout << "Integral approx. result: " << result << endl;

    return 0;
}
