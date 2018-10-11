#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;
#define TRUE 1
#define FALSE 0

class queen
{ int flag=0;
public: void print_solution(int n,int x[]);
int place(int x[],int k);
void nqueens(int n);
};

void queen::print_solution(int n,int x[])
{
char c[10][10];
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
c[i][j]='0';
for(int i=1;i<=n;i++)
c[i][x[i]]='1';
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
cout<<c[i][j]<<" ";
cout<<endl;
}
}

int queen::place(int x[],int k)
{
for(int i=1;i<k;i++)
if(x[i]==x[k]||i-x[i]==k-x[k]||i+x[i]==k+x[k])
return FALSE;
return TRUE;
}

void queen::nqueens(int n)
{
int x[10];
int count=0;
int k=1;
x[k]=0;
while(k!=0)
{
x[k]+=1;
while((x[k]<=n)&&(!place(x,k)))
x[k]+=1;
if(x[k]<=n)
{
if(k==n && !flag)
{
    flag=1;
print_solution(n,x);
}
else
{
k++;
x[k]=0;
}
}
else
k--;
}
if(flag==0)
    cout<<"Not possible";
}

int main()
{
int n;
queen q;

cin>>n;
q.nqueens(n);
getch();
return 0;
}
