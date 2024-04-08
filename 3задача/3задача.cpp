#include <iostream>
#include <cmath>
using namespace std;

double resultFunctionForX(double x) {
    return pow(x, 6) - 1;
}

double chordsMethod(double a, double b) {
    if (resultFunctionForX(a) * resultFunctionForX(b) >= 0) {
        cout << "Incorrect a and b. They need to be different values (f(a)* f(b) < 0)\n";
        return 0;
    }

    double c = INT_MAX;

    // f' = 6x^5;
    double max = abs(6 * pow(b, 5));
    double min = abs(6 * pow(a, 5));
    double error1 = max - min;
    double errorCount = 1000;

    while (errorCount >= 0.0001 || errorCount <= -193) {
        c = a - (resultFunctionForX(a) * (b - a)) / (resultFunctionForX(b) - resultFunctionForX(a));

        errorCount = error1 * abs(c - a);

        if (resultFunctionForX(c) * resultFunctionForX(a) < 0) {
            b = c;
        }
        else {
            a = c;
        }
    }

    return c;
}

int main()
{
    // x^6 - 1 = 0 има две реални решения
    // (x^3 - 1)(x^3 + 1) = 0
    // x=1 и x=-1
    //но само 1 е положително
    double a = 0, b = 2;
    double a1 = -2, b1 = 0;

    cout << chordsMethod(a, b) << " Which ~ equals to 1\n";

    cout << chordsMethod(a1, b1) << " Which ~ equals to -1\n";
    cout << "Second one not true -1 < 0";
    return 0;
}