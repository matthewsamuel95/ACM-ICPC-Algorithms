#include<iostream>
using namespace std;

void copySetBitsInaRange(unsigned int &a, unsigned int b, unsigned int l, unsigned int r) {

    // assuming ints are stored using 32 bits
    if (l < 1 || r > 32) {
        return;
    }

    // for a given range
    for(int i=l; i<=r; i++){
        // Find a mask (a number whose only set bit is at i'th position)
        int mask = 1 << (i-1);

        // if i'th bit is set in y, set i'th bit in x also
        if (b & mask) {
            a = a | mask;
        }
    }
}

int main() {
    unsigned int a , b , l , r;
    cout<<"enter first number: ";
    cin>>a;

    cout<<"enter second number: ";
    cin>>b;

    cout<<"enter range: ";
    cin>>l>>r;

    copySetBitsInaRange(a, b, l, r);
    cout<<"modified value of first number after copying set bits from the range is "<<a<<endl;

    return 0;
}