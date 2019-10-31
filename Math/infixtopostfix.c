#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *stack;
int top=-1,n=10000;
void push(char c)
{
	stack[++top]=c;
}
void pop()
{
	stack[top--]='\0';
}
int main()
{
	int i;
	char c;
	char *arr=(char *)calloc(sizeof(char),n);
	printf("Enter the Infix Expression : ");
	scanf("%s",arr);
	stack=(char *)calloc(sizeof(char),n+1);
	printf("Postfix Expression :");
	for (int i = 0; i < n; ++i)
	{
		c=arr[i];
		if((c>='a' && c<='z') || (c>='A' && c<='Z'))
		{
			printf("%c",c);
		}
		else if((c=='(') || (c=='^'))
		{
			if(stack[top]=='^')
			{
				printf("%c",stack[top]);
				pop();
			}
			push(c);
		}
		else if((c=='/') || (c=='*'))
		{
			if(stack[top]=='^')
			{
				printf("%c",stack[top]);
				pop();
			}
			else if((stack[top]=='/') || (stack[top]=='*'))
			{
				printf("%c",stack[top]);
				pop();
			}
			push(c);
		}
		else if((c=='+') || (c=='-'))
		{
			if((stack[top]=='^') || (stack[top]=='/') || (stack[top]=='*'))
			{
				printf("%c",stack[top]);
				pop();
			}
			else if((stack[top]=='+') || (stack[top]=='-'))
			{
				printf("%c",stack[top]);
				pop();
			}
			push(c);
		}
		else if(c==')')
		{
			while(stack[top]!='(')
			{
				printf("%c",stack[top]);
				pop();
			}
			pop();
		}
	}
	while(top>=0)
	{
		printf("%c",stack[top]);
		pop();
	}
	printf("\n");
	return 0;
}
