#include<iostream>
using namespace std;

int countSetBits(int n) {
    int setBits = 0;
    while(n > 0){
        if(n&1){
            setBits++;
        }
        n>>=1;
    }
    return setBits;
}

int main(){
    int a,b;
    cin>>a>>b;

    // take the XOR of both the numbers and then count the set bits in that XOR
    int _xor = a^b;
    int answer = countSetBits(_xor);

    cout<<"number of bits to be flipped "<<answer<<endl;

    return 0;
}