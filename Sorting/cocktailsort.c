#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define size 20
int temp,i;
void bubblesort(int *A)
{
    int j,temp;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
    printf("\nBubble Sort Array:\n");
    for(i=0;i<size;i++)
        printf("%d ",A[i]);
}

void impbubblesort(int *B)
{
    int bound=size,t,j;
    i=0;
    do
    {
        t=0;
        for(i=0;i<bound-1;i++)
        {
            if(B[i]>B[i+1])
            {
                temp=B[j];
                B[j]=B[j+1];
                B[j+1]=temp;
                t=i;
            }
        }
        bound=t;
    }while(t>0);
    printf("\nImproved Bubble Sort Array:\n");
    for(i=0;i<size;i++)
        printf("%d ",B[i]);
}

void cocktailsort(int *A)
{
    int start=0,swap=1,j;
    int end=size-1;
    while(swap==1)
    {
        swap=0;
        for(j=start;j<end;j++)
        {
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                swap=1;
            }
        }
        if(swap==0)
            break;
        swap=0;

        end--;
        for(j=end-1;j>=start;j--)
        {
            if (A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                swap=1;
            }
        }
        start++;
    }

    printf("\nCocktail shaker Array:\n");
    for(i=0;i<size;i++)
        printf("%d ",A[i]);
}
int partition(int *A,int low,int high)
{
    int pivot=A[high];
    int j;
    i=low-1;
    for(j=low;j<=high-1;j++)
    {
        if(A[j]<=pivot)
        {
            i++;
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    temp=A[i+1];
    A[i+1]=A[high];
    A[high]=temp;
    return(i+1);
}
void quicksort(int *A,int low,int high)
{
    int pi;
   if (low<high)
   {
       pi=partition(A,low,high);
       quicksort(A,low,pi-1);
       quicksort(A,pi+1,high);
   }
}


int main()
{
    srand(time(NULL));
    int *A,*B,*C;
    int i;
    A=(int*)malloc(sizeof(int)*size);
    B=(int*)malloc(sizeof(int)*size);
    C=(int*)malloc(sizeof(int)*size);
    for (i=0;i<20;i++)
        A[i]=B[i]=C[i]=rand()%20;
    printf("Original Array:\n");
    for(i=0;i<size;i++)
        printf("%d ",A[i]);
    bubblesort(B);
    //impbubblesort(B);
    cocktailsort(A);
    quicksort(C,0,size);
}
