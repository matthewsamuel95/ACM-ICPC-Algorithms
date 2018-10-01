#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    double a = 0;
    cout<<"Enter an integer:"<<endl;
    cin>>a;
    if (a <= 0) return 0;
    printf("Square root of %lf is: %.0lf \n",a,floor(sqrt(a)));
    return 0;
}