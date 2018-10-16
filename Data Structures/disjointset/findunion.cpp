
/*
Disjoint set example of find and union 

Question Url : https://www.hackerrank.com/challenges/merging-communities/problem

*/

#include <bits/stdc++.h>

using namespace std;

long find(int x,vector<int>&a)
{
    while(1)
    {
        if(a[x]<0)
        {
            return x;
        }
        else
        {
            x=a[x];
        }
    }
}
int main()
{
  int n;
    cin>>n;
    vector<int>arr(n+1,-1);
    int m;
    cin>>m;
    int i,j,x;
    char qt;
    long p1,p2;
    while(m--)
    {
        cin>>qt;
        if(qt=='M')
        {
    
        cin>>i>>j;
         p1=find(i,arr);
        p2=find(j,arr);
        if(p1!=p2)
        {
            arr[p1]=arr[p1]+arr[p2];
            arr[p2]=p1; //making p1 as parrent of that node;
            arr[j]=p1; //collapsing the tree what i have learned to minimize the time to find the parent;    
            
        }
        
        }
        else
        {
            cin>>x;
           
            cout<<abs(arr[find(x,arr)])<<endl;   // finding how many of them are in a group basically union set 
        }
    }
  
    
      
    
    return 0;
}



