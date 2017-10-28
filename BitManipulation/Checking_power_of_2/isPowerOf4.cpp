#include <iostream>
using namespace std;

bool isPowerOfFour(int num) {
    return (num > 0) && !(num & (num - 1)) && !((num - 1) % 3);
}

int main() {
    cout << isPowerOfFour(64) << endl;
    return 0;
}
