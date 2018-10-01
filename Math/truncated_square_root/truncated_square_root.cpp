#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    long long int n,x = 0,count=0;
    cout<<"Enter an integer: "<<endl;
    cin>>n;
    for(int i = 1;x <= n;i += 2) {
        x += i;
        count++;
    }
    printf("Square root of %lld is: %lld\n",n,count-1);
    return 0;
}