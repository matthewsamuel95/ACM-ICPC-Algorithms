#include <stdio.h>
#include <stdlib.h>

#define MAX 500

struct Stack
{
    int top;
    int* a;
};

typedef struct Stack stack;

stack* createStack()
{
    stack *s = malloc(sizeof(stack));
    s->top = -1;
    s->a = malloc(MAX * sizeof(int));
}

int isEmpty(stack* s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(stack *s)
{
    if (s->top == MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(stack *s, int n)
{
    if (isFull(s))
    {
        printf("Stack overflow\n");
    }
    else
    {
        s->a[++s->top] = n;
        printf("%d pushed to stack\n", n);
    }
}

void pop (stack *s)
{
    if (isEmpty(s))
    {
        printf("Underflow\n");
    }
    else
    {
        printf("%d popped from the stack", s->a[s->top]);
        s->top--;
    }
}

int peek(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
    }
    else
    {
        return s->a[s->top];
    }
}

void display(stack* s)
{
    int i = 0;
    for (i = s->top; i >= 0; i--)
    {
        printf("%d\t", s->a[i]);
    }
    printf("\n");
}

int main()
{
    stack* s = createStack();
    int c = 0;
    printf("Enter 1 to push elements to stack.\nEnter 2 to pop elements from the stack.\nEnter 3 to peek topmost element in stack.\nEnter 4 to display content of the stack.\n");
    scanf("%d", &c);
    do
    {
        switch (c)
        {
            case 1: printf ("Enter element to be pushed: ");
                    int n = 0;
                    scanf("%d", &n);
                    push(s, n); break;
            case 2: pop(s); break;
            case 3: printf("%d\n", peek(s)); break;
            case 4: display(s); break;
            default: printf("Invalid input");
        }
        scanf("%d", &c);
    } while (c != -1);
    return 0;
}