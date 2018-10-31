#include <bits/stdc++.h>
using namespace std;
int n=0;
int val[100000];
int m=1000000;
int mx[1000][1000];
void print(int x,int y)
{
	if(x==y)
	{
		cout<<x-1;
	}
	else
	{
		cout<<"(";
		print(x,mx[y][x]);
		print(mx[y][x]+1,y);
		cout<<")";

	}

}

void fun()
{
    
    for(int i=0;i<=n;i++)
        mx[i][i]=0;
    for(int x=2;x<n;x++)
    {
        for(int j=1;j<n-x+1;j++)
        {
            int i=j+x-1;
            mx[j][i]=m;
            for(int k=j;k<i;k++)
            {
                
                int w=mx[j][k]+mx[k+1][i]+val[j-1]*val[k]*val[i];
		if(w<mx[j][i])
		{
		mx[i][j]=k;
                mx[j][i]=min(mx[j][i],w);
		}
            }
           
            
            
        }
    }
	print(1,n-1);
	cout<<endl;	
    cout<<mx[1][n-1]<<endl;

}

int main() {
  
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    fun();
    return 0;
}
