#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s,t;
        cin>>s;
        cin>>t;
        int flag = 0;
        int m = s.length();
        int n = t.length();
        if(t.length()<=s.length() || s[0]!=t[0])
        {
            cout<<"NO"<<endl;
        }
        else
        {
            int i=1,j=1;
            while(i<m && j<n)
            {
                if(s[i]==t[j])
                {
                    i++;
                    j++;
                }
                else if(s[i-1]==t[j])
                {
                    j++;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==0)
            {
                while(j<n)
                {
                    if(s[m-1]==t[j])
                        j++;
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag==1)
            {
                cout<<"NO"<<endl;
            }
            else
            {
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}
