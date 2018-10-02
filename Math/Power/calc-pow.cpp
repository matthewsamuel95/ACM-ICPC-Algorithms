#include <iostream>
#include <cmath>
using namespace std;

double getPow(double n, double e) {
    if (e < 0) {
      return 1;
    }
    double T = 1;
    for(int k = 1; k <= e; k++) {
      T = T * n;
    }
    return T;
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
