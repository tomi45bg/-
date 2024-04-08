#include <iostream>
#include<string>
#include<cmath>
#include <iomanip>
using namespace std;

bool findPositiveOrNot(string n) {
    char firstNum = n[0];
    if (firstNum == '0') {
        return 0;
    }

    return 1;
}

double returnWholePart(string n) {
    string subStringFirst11 = n.substr(1, 11);
    double c = 0;
    int count = 0;

    for (int i = 10; i >= 0; i--) {
        string digit = subStringFirst11.substr(count, 1);
        count++;
           
        double digitInteger = stoi(digit);
        c += digitInteger * pow(2, i);
    }

    return c;
}

double returnDecimalPart(string n) {
    string decimalPart = n.substr(12, 52);
    double f = 0;
    int count = 0;

    for (int i = -1; i >= -52; i--) {
        string digit = decimalPart.substr(count, 1);
        count++;

        double digitInteger = stoi(digit);
        f += digitInteger * pow(2, i);
    }

    return f;
}

double binaryToDecimal(string n) {
    bool s = findPositiveOrNot(n);
    int s1;
    if (s == true) {
        s1 = 1;
    }
    else {
        s1 = 0;
    }
    double c = returnWholePart(n);
    double f = returnDecimalPart(n);

    double firstPart = pow(-1, s1); 
    double secondPart = pow(2, c - 1023); 
    double thirdPart = 1.0 + f; 

    double num = firstPart * secondPart * thirdPart;

    return num;
}

int main()
{
    //1100000010101001001100000000000000000000000000000000000000000000
    string binaryNumber;

    cin >> binaryNumber;

    double decimalNumber = binaryToDecimal(binaryNumber);
    cout << fixed << setprecision(15) << decimalNumber << std::endl;

    return 0;
}