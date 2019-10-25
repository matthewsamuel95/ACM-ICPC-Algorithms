#include<iostream>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;

    // take the XOR of both the numbers and then count the set bits in that XOR
    int _xor = a^b;
    int answer = __builtin_popcount(_xor);

    cout<<"number of bits to be flipped "<<answer<<endl;

    return 0;
}
