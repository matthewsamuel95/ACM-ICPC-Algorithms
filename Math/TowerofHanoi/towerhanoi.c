#include<stdio.h>

void tower(int no,char a,char b,char c);

int main()
{
    int no;
    printf("Enter total number of disks:");
    scanf("%d",&no);
    tower(no,'A','B','C');
    return 0;
}

void tower(int no,char a,char b,char c)
{
    if(no>0)
    {
        tower(no-1,a,c,b);
        printf("%c->%c\n",a,c);
        tower(no-1,b,a,c);
    }
}
