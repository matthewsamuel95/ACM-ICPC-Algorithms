#include <cstdlib>
#include <iostream>

bool PromptForValues(int& num1, int& num2);
int gcd(int a, int b);
int gcd_impl(int a, int b);

int main() {
    int num1;
    int num2;

    while (PromptForValues(num1, num2)) {
        std::cout << "GCD(" << num1 << "," << num2 << ") = " << gcd(num1, num2) << '\n';
    }
    return 0;
}

bool PromptForValues(int& num1, int& num2) {
    std::cout << "Enter two numbers: ";

    return static_cast<bool>(std::cin >> num1 >> num2);
}

int gcd(int a, int b) {
    int absA = std::abs(a);
    int absB = std::abs(b);

    return (absA > absB) ? gcd_impl(absA, absB) : gcd_impl(absB, absA);
}

int gcd_impl(int a, int b) {
    if (b == 0) {
        return a;
    }
    if (b == 1) {
        return 1;
    }
    int remainder = a % b;

    if (remainder == 0) {
        return b;
    }
    return gcd_impl(a, remainder);
}
