//http://codeforces.com/problemset/problem/4/A
#include <iostream>

using namespace std;

int main()
{int w;
cin >> w;
if ((w >2)&&(w<= 100))
{
    if ((w % 2) == 0)
    cout << "YES" ;
    else
    cout << "NO";
}
if ((w ==2) || (w==1)  )
    cout << "NO";
    return 0;
}
