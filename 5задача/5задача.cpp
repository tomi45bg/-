#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

double interpolation(double x[], double y[], int index, double valueWeSearch) {
    double value = 0;

    value = y[index] * (((valueWeSearch * 1.0 - x[index + 1]) * (valueWeSearch - x[index + 2]))
        / ((x[index] * 1.0 - x[index + 1]) * (x[index] - x[index + 2])));
        
    value += y[index + 1] * (((valueWeSearch * 1.0 - x[index]) * (valueWeSearch - x[index + 2]))
        / ((x[index + 1] * 1.0 - x[index]) * (x[index + 1] - x[index + 2])));
        
    value += y[index + 2] * (((valueWeSearch * 1.0 - x[index]) * (valueWeSearch - x[index + 1]))
        / ((x[index + 2] * 1.0 - x[index]) * (x[index + 2] - x[index + 1])));


    return value;
}

int main()
{
    double x[6] = { -0.40, 0.60, 1.60, 2.60, 3.60, 4.60 };
    double y[6] = { 0.3770, 0.0971, 0.7385, 0.7729, 0.7262, 0.6705 };

    double value = interpolation(x, y, 1, 0.76);
    cout << "The value is: " << fixed << setprecision(4) << value << endl;

    return 0;
}