//http://codeforces.com/problemset/problem/50/A
#include <iostream>

using namespace std;

int main()
{
    long long n,m,Domino=0,width,length;
    cin >>n>>m;
    if ((m==1)&&(n==1))
    {
        Domino=0;
    }
    else
    {
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

        if(((width%2)==0)&&((length%2)==0))
            Domino=(width*length)/(2);

        else if(((width%2)!=0)&&((length%2)==0))
            Domino=(width)*((length/2));

        else if(((width%2)==0)&&((length%2)!=0))
            Domino=((width/2))*(length);

        else if(((width%2)!=0)&&((length%2)!=0))
            Domino=((width)*(length/2))+(width/2);
    }
        cout << Domino;
    return 0;
}
