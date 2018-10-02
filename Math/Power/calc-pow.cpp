#include <iostream>
#include <cmath>
using namespace std;

double getPow(double x, double n) {
    return pow(x, n);
}

int main() {
    double x;
    double n;
    cout << "Enter the number you want to raise" << endl;
    cin >> x;
    cout << "Enter the exponent" << endl;
    cin >> n;
    double result = getPow(x, n);
    cout << result << endl;
    return 0;
}
