#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int array[],int sk,int size)
{
int flag=0,first=0,middle,x;
int last=size-1;
int position=-1;

while(first<=last && flag==0)
{
    middle=(first+last)/2;
    if(array[middle]==sk)
    {
        flag=1;
        position=middle;
    }
    else if(array[middle]>sk)
        last=middle-1;
    else
        first=middle+1;
}

return position;
}

int main()
{

int x,size,sk,result;

printf("Enter the Size of the Array ");
scanf("%d",&size);

int array[size];

for(x=0;x<size;x++)
{
    printf("Enter Value %d into Array ",x+1);
    scanf("%d",&array[x]);
}
 printf("Enter the Search Key ");
 scanf("%d",&sk);

 result=BinarySearch(array,sk,size);

 if(result==-1)
     printf("The Value is Not Found");
 else
     printf("The Index of the Value is %d",result);

    return 0;
}
