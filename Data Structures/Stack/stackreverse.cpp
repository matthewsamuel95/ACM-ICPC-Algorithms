#include<iostream>
#include<string.h>
using namespace std;
int top=-1;
char stack[30];
void push(char x)
{
	if(top==29)
	{
		cout<<"stack is overflow";
		return;
	}
	top=top+1;
	stack[top]=x;
}
void pop(char x)
{
	if(top==-1)
	{
		cout<<"stack is empty";
		return;
	}
top=top-1;
}
void print()
{
	int i;
	for(i=0;i<=top;i++)
	{
		cout<<stack[i];
	}
}
main()
{
	char str[30],t,x;
	int r,i;
	cout<<"enter a string ";
	cin>>str;
	r=strlen(str);
	for(i=0;i<r;i++)
	{ t=str[i];
	push(t);	
	}
		for(i=0;i<r;i++)
	{ x=str[i];
		cout<<stack[top];	
	pop(x);

	}
	
}
