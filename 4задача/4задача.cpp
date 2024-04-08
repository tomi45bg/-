#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

double interpolation(double y[], int monthIndex) {
    double value = 0;
    double data[3];
    // нуждаем се от 3 елемента, които да обграждат индекса на месеца в интервал

    int amount = 0;
    int index = monthIndex - 1;

    //търсим елементи наляво(2)
    while (amount != 2) {
        if (y[index - 1] == INT_MAX) {
            index--;
        }

        if (index <= 0) {
            index = 10;
        }

        if (y[index - 1] != INT_MAX) {
            index--;
            data[amount] = y[index];
            amount++;
        }
    }

    index = monthIndex - 1;

    //търсим елементи надясно(1)
    while (amount != 3) {
        if (y[index + 1] == INT_MAX) {
            index++;
        }

        if (index >= 11) {
            index = -1;
        }

        if (y[index + 1] != INT_MAX) {
            index++;
            data[amount] = y[index];
            amount++;
        }
    }
    if (monthIndex == 12) {
        value = data[1] * (((monthIndex*1.0 - (monthIndex - 1)) * (monthIndex - 1))
            / (((monthIndex - 2) * 1.0 - (monthIndex - 1)) * ((monthIndex - 2) - 1)));

        value += data[0] * (((monthIndex * 1.0 - (monthIndex - 2)) * (monthIndex -1))
            / (((monthIndex - 1) * 1.0 - (monthIndex - 2)) * ((monthIndex - 1) - 1)));

        value += data[2] * (((monthIndex * 1.0 - (monthIndex - 2)) * (monthIndex - (monthIndex - 1)))
                / (((1) * 1.0 - (monthIndex - 2)) * ((1) - (monthIndex - 1))));
    }
    else if (monthIndex == 3) {
        value = data[1] * (((monthIndex * 1.0 - (monthIndex - 1)) * (monthIndex - (monthIndex + 3)))
            / (((monthIndex - 2) * 1.0 - (monthIndex - 1)) * ((monthIndex - 2) - (monthIndex + 3))));
        value += data[0] * (((monthIndex * 1.0 - (monthIndex - 2)) * (monthIndex - (monthIndex + 3)))
            / (((monthIndex - 1) * 1.0 - (monthIndex - 2)) * ((monthIndex - 1) - (monthIndex + 3))));
        value += data[2] * (((monthIndex * 1.0 - (monthIndex - 2)) * (monthIndex - (monthIndex - 1)))
                / (((monthIndex + 3) * 1.0 - (monthIndex - 2)) * ((monthIndex + 3) - (monthIndex - 1))));
    }

    return value;
}

int main()
{
    // масива х е пълен с индекси за месеците
    int x[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    // y описва стойностите за всеки месец
    // INT_MAX е default стойност, нямаме все още инфо;
    double y[12] = { 0.388, 0.844, INT_MAX, INT_MAX, INT_MAX, -1.192,
        -0.996, -1.382, -1.053, 0.624, 0.549, INT_MAX };

    cout << "The value for December is approximately: " << fixed << setprecision(3) << interpolation(y, 12);
    cout << endl;
    cout << "The value for March is approximately: " << interpolation(y, 3);

    return 0;
}