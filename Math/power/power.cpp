#include<iostream>

using namespace std;

int main(){
    int b,i;
    float a,result=1.0;
    cout<<"Enter the number and the nth power : ";
    cin>>a>>b;
    for(i=1;i<=b;i++){
        result = result * a;
    }
    cout<<"Result : "<<result;
    return 0;
}
