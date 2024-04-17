#include <iostream>
#include <vector>
using namespace std;

// Функция за пресмятане на разделената разлика
double divided_difference(const vector<double>& x, const vector<double>& y, int start, int end) {
    if (start == end) {
        return y[start];
    }
    else {
        return ((divided_difference(x, y, start + 1, end) - divided_difference(x, y, start, end - 1))) / (x[end] - x[start]);
    }
}

// Функция за пресмятане на интерполационния полином на Нютон
double newton_interpolation(const vector<double>& x, const vector<double>& y, double target, int n) {
    double result = y[0];
    for (int i = 1; i < n; ++i) {
        double term = divided_difference(x, y, 0, i);
        for (int j = 0; j < i; ++j) {
            term *= (target - x[j]);
        }
        result += term;
    }
    return result;
}

// Съответните стойности f(x)
double functionFirstReturn(double x) {
    if (x < 0) {
        return -pow(abs(x), 1.0 / 5.0);
    }
    return pow(x, 1.0 / 5.0);
}

double functionSecondReturn(double x) {
    return pow(2, x);
}

int main() {
    vector<double> x = { -2, -1, 0, 1, 2 }; // Зададени точки x
    vector<double> y;
    int n = x.size(); // Брой точки
    double target = pow(0.25, 1.0 / 5.0);

    //Първа функция 
    for (int i = 0; i < n; i++) {
        y.push_back(functionFirstReturn(x[i]));
    }

    double approximation = newton_interpolation(x, y, target, n);
    cout << "Approximation of f(0.25 ^(1/5)): " << approximation << endl;

    //Втора функция
    y.clear();
    for (int i = 0; i < n; i++) {
        y.push_back(functionSecondReturn(x[i]));
    }

    approximation = newton_interpolation(x, y, target, n);
    cout << "Approximation of f(0.25 ^(1/5)): " << approximation << endl;

    return 0;
}
