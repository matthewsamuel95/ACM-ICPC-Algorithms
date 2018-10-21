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
  char infix[size],postfix[size],item;
  char temp;
  int i=0,j=0;
  printf("enter infix expression\n");
  scanf("%s",infix);
  while(infix[i]!='\0')
   {
    item=infix[i];
    if(item=='(')
    {
       push(item);
    }
    else if(item>='a'&& item<='z'||item>='A'&& item<='Z')
    {
      postfix[j]=item;
      j++;
     }
    else if(is_operator(item)==1)
    {
      temp=pop();
      while(is_operator(temp)==1 && precendence(temp)>=precendence(item))
      {
       postfix[j]=temp;
       j++;
       temp=pop();
      }
     push(temp);
     push(item);
    }
    else if(item==')')
    {
      temp=pop();
      while(temp!='(')
     {
      postfix[j]=temp;
      j++;
      temp=pop();
     }
   }
   else
   {
       printf("\n invalid\n");
       exit(0);
   }
   i++;
  }
  while(top>-1)   //for no paranthesis
  {
    postfix[j]=pop();
    j++;
  }
  postfix[j]='\0';
  printf("the postfix expression is\n");
  printf("%s",postfix);
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