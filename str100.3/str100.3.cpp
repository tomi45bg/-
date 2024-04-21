#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Функция за изчисляване на коефициентите на линейна функция
void linear_least_squares(vector<double> x, vector<double> y, double& a1, double& a0) {
    double x_average = 0.0, y_average = 0.0;

    double Sxy = 0.0, Sxx = 0.0;

    for (int i = 0; i < x.size(); i++) {
        Sxy += (x[i] - x_average) * (y[i] - y_average);
        Sxx += (x[i] - x_average) * (x[i] - x_average);

        if ((i + 1) == x.size()) {
            Sxy /= x.size();
            Sxx /= x.size();
        }
    }

    a1 = Sxy / Sxx;

    a0 = y_average - (a1 * x_average);
}

// Функция за изчисляване на трета степен
void cubic_least_squares(vector<double> x, vector<double> y, double& a3, double& a2, double& a1, double& a0) {
    double sumX = 0, sumY = 0, sumXX = 0, sumXXX = 0, sumXXXX = 0, sumXY = 0, sumXXY = 0, sumXXXY = 0;
    int n = x.size();

    // Изчисляване на сумите
    for (int i = 0; i < n; ++i) {
        double xi = x[i];
        double yi = y[i];
        sumX += xi;
        sumY += yi;
        sumXX += xi * xi;
        sumXXX += xi * xi * xi;
        sumXXXX += xi * xi * xi * xi;
        sumXY += xi * yi;
        sumXXY += xi * xi * yi;
        sumXXXY += xi * xi * xi * yi;
    }

    // Намиране на коефициентите чрез метода на най-малките квадрати
    double detA = n * sumXX * sumXXXX + 2 * sumXX * sumXX * sumXX + 2 * sumXXX * sumX * sumX - 2 * sumXX * sumX * sumX - n * sumXXXX * sumX - n * sumXXX * sumXX;
    a0 = (sumY * sumXX * sumXX - sumX * sumXY * sumXX + sumXY * sumXX * sumX - sumXXY * sumX * sumX) / detA;
    a1 = (n * sumXY * sumXX - sumX * sumY * sumXX + sumX * sumXY * sumX - sumXX * sumXXY * sumX) / detA;
    a2 = (sumY * sumXXX * sumXX - sumXX * sumXXY * sumXX + n * sumXXY * sumXXXX - n * sumXXX * sumXXXY) / detA;
    a3 = (n * sumXXY * sumXX - sumXXX * sumY * sumXX + sumXXX * sumXX * sumXXY - sumXX * sumXXY * sumXX) / detA;
}

int main() {
    vector<double> x = { -2.0, -1.5, -1.0, -0.5, 0.0, 0.5, 1.0, 1.5, 2.0 };
    vector<double> y = { 8.74, -31.72, -1.55, -0.136, 0.00, 0.136, 1.55, 31.72, -8.74 };

    double a0, a1;
    linear_least_squares(x, y, a1, a0);
    double b0 = 0, b1 = 0, b2 = 0, b3 = 0;
    cubic_least_squares(x, y, b3, b2, b1, b0);
    cout << "Linear approximation: y = " << a1 << "x" << " + " << a0 << endl;
    cout << "Cubic approximation: y = " << b3 << "x^3" << " + " << b2 << "x^2" << "+" << b1 << "x" << "+" << b0 << endl;

    return 0;
}
