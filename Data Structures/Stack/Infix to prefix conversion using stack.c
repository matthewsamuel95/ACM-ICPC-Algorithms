#include<stdio.h>
#include<string.h>
#define size 100
int top=-1;
char stack[size];
int is_operator(char symbol);
char pop();
void push(char item);
int precendence(char symbol);
int main()
{
  char infix[size],prefix[size],item;
  char temp;
  int i=0,j=0,len;
  printf("enter infix expression\n");
  gets(infix);
  len=strlen(infix);
  for(i=len;i>=0;i--)
  {
   item=infix[i];
   if(item==')')
   {
    push(item);
   }
   else if(item>='a'&& item<='z'||item>='A'&& item<='Z')
   {
    prefix[j]=item;
    j++;
   }
   else if(is_operator(item)==1)
   {
    temp=pop();
    while(is_operator(temp)==1 && precendence(temp)>=precendence(item))
    {
     prefix[j]=temp;
     j++;
     temp=pop();
    }
    push(temp);
    push(item);
   }
   else if(item=='(')
   {
     temp=pop();
     while(temp!=')')
     {
      prefix[j]=temp;
      j++;
      temp=pop();
     }
   }
  }
  while(top>-1)
  {
    prefix[j]=pop();
    j++;
  }
  prefix[j]='\0';
  printf("the prefix expression is\n");
  printf("%s",strrev(prefix));
  return 0;
}

void push(char item)
 {
    if(top>=size-1)
    printf("stack overfloaw\n");
    else
    {
     top++;
     stack[top]=item;
    }
}

int is_operator(char symbol)
{
    if(symbol=='^'||symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/')
        return 1;
    else
        return 0;
}
 
char pop()
{
    char item;
    item=stack[top];
    top--;
    return item;
}
  
int precendence(char symbol)
{
    if(symbol=='^')
       return 3;
    else if(symbol=='/'||symbol=='*')
       return 2;
    else if(symbol=='+'||symbol=='-')
        return 1;
    else
        return 0;
 }