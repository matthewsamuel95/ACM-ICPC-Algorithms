#include <cstdio>
#include <iterator>
#include <vector>
using namespace std;
const int witness[]={2,3,5,7};
const int witness_size=4; ///remember to edit this value too
/* Note that different witness arrays will cause the function to have different accuracies.
But according to wikipedia: https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test

    if n < 2,047, it is enough to test a = 2;
    if n < 1,373,653, it is enough to test a = 2 and 3;
    if n < 9,080,191, it is enough to test a = 31 and 73;
    if n < 25,326,001, it is enough to test a = 2, 3, and 5;
    if n < 3,215,031,751, it is enough to test a = 2, 3, 5, and 7; (I am using this)
    if n < 4,759,123,141, it is enough to test a = 2, 7, and 61;
    if n < 1,122,004,669,633, it is enough to test a = 2, 13, 23, and 1662803;
    if n < 2,152,302,898,747, it is enough to test a = 2, 3, 5, 7, and 11;
    if n < 3,474,749,660,383, it is enough to test a = 2, 3, 5, 7, 11, and 13;
    if n < 341,550,071,728,321, it is enough to test a = 2, 3, 5, 7, 11, 13, and 17.

    Note that for the correctness of the algorithm, the witness array should only be filled with prime numbers.
*/

bool isPrime(int i){
    ///check for the simple cases
    if (i==1) return false;
    if (i==2) return true;
    if (!(i&1)) return false;
    for (int x=0;x<witness_size;x++){
        if (witness[x]==i) return true;
    }

    vector<int> pow;  ///this holds the bits of i with all the trailing zeros striped off
    int s=0; ///number of trailing zeros

    int _i=i-1;
    while (!(_i&1)){
        s++;
        _i>>=1;
    }

    while (_i){
        pow.push_back(_i&1);
        _i>>=1;
    }

    long long curr;
    for (int x=0;x<witness_size;x++){
        curr=1;
        for (vector<int>::reverse_iterator it=pow.rbegin();it!=pow.rend();it++){
            if (*it){
                curr=(curr*curr)%i;
                curr=(curr*witness[x])%i;
            }
            else{
                curr=(curr*curr)%i;
            }
        }

        if (curr==1 || curr==i-1) goto _end;

        for (int x=1;x<s;x++){
            if (curr!=i-1) {
                curr=(curr*curr)%i;
                if (curr==1) return false;
            }
            else goto _end;
        }
        if (curr!=i-1) return false;
        _end:;
    }

    return true;
}

int main(){
    ///program to test if it works
    for (int x=1;x<=1000;x++){
        if (isPrime(x)) printf("%d\n",x);
    }
}
