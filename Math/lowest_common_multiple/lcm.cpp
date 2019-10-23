#include <bits/stdc++.h>
using namespace std;

int lcm(int a,int b)
{
    int temp = a;
    while(temp%b!=0)
    {
        temp+=a;
    }
    return temp;
}

int main()
{
    cout<<lcm(3,9)<<endl;//Answer: 9
    cout<<lcm(24,36)<<endl;//Answer: 72
    cout<<lcm(12,80);//Answer: 240
    return 0;
}