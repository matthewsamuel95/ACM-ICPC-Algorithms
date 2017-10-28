#include <iostream>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    int retval = 0;

    for (int i = 0; i < 32; i++) {
        retval <<= 1;
        retval |= (n & 1);
        n >>= 1;
    }

    return retval;
}

int main() {
    // (Input)  12345678:    00000000 10111100 01100001 01001110
    // (Output) 1921400064:  01110010 10000110 00111101 00000000
    cout << reverseBits(12345678) << endl;
    return 0;
}
