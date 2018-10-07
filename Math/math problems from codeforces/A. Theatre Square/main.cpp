//http://codeforces.com/problemset/problem/1/A
#include <iostream>

using namespace std;

int main()
{
    long long n,m,a,numberOFsquares,width,length;
    cin >>n>>m>>a;
    if (n>m)
    {
        width=n;
        length=m;
    }
    else
    {
        width=m;
        length=n;
    }
    if(((width%a)==0)&&((length%a)==0))
        numberOFsquares=(width*length)/(a*a);
    else if(((width%a)!=0)&&((length%a)==0))
        numberOFsquares=((width/a)+1)*((length/a));
    else if(((width%a)==0)&&((length%a)!=0))
        numberOFsquares=((width/a))*((length/a)+1);
    else if(((width%a)!=0)&&((length%a)!=0))
        numberOFsquares=((width/a)+1)*((length/a)+1);
    cout << numberOFsquares;
    return 0;
}
