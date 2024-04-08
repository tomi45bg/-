#include <iostream>
#include <cmath>
using namespace std;

double resultFunctionForX(double x) {
    return 4 * tan(x) - 3 * cos(x);
}

double bisection(double a, double b) {
    if (resultFunctionForX(a) * resultFunctionForX(b) >= 0) {
        cout << "Неправилни а и б! Трябва да са с различни значи стойностите им\n";
        return 0;
    }

    double c = a;
    while ((b - a) >= 0.01) {
        c = (a + b) / 2;
        if (resultFunctionForX(c) == 0.0)
            break;
        else if (resultFunctionForX(c) * resultFunctionForX(a) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}

int main() {
    double a1 = 0, b1 = 1;
    double a2 = 2, b2 = 3;
    cout << "First continuous root of the equation is: " << bisection(a1, b1) << " + 2kpi" << endl;
    cout << "Second continuous root of the equation is: " << bisection(a2, b2) << " + 2kpi" << endl;
    return 0;
}