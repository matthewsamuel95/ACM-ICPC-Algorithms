/*
 * shell sort
 */
#include <stdio.h>

void shellsort(int arr[],int n);
void print(int arr[],int );
int main() {
    int n=8;
    int arr[]={4,3,7,2,1,9,5,6};
    printf("Before sorting\n");
    print(arr,n);


    //shell sort function
    shellsort(arr,n);
    printf("After sorting\n");
    print(arr,n);
    return 0;
}
void shellsort(int a[], int n)
{
    int i, j, k, temp;
    // Gap 'i' between index of the element to be compared, initially n/2.
    for(i = n/2; i > 0; i = i/2)
    {
        for(j = i; j < n; j++)
        {
            for(k = j-i; k >= 0; k = k-i)
            {
                // If value at higher index is greater, then break the loop.
                if(a[k+i] >= a[k])
                    break;
                    // Switch the values otherwise.
                else
                {
                    temp = a[k];
                    a[k] = a[k+i];
                    a[k+i] = temp;
                }
            }
        }
    }
}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d , ",arr[i]);

    printf("\n");
}
