#include<stdio.h>

/*
 * @ar_size array size
 * @ar array pointer
 */
void selectionsort(int ar_size, int * ar) 
{ 
  for(int j=0; j<ar_size; j++)
        {
          int temp;
          int imin=j;
                 for(int i=j+1; i=ar_size; i++)
                  {
                  if(ar[i]<ar[imin])
                  {
                  imin=i;
                 }
                  }
          
          temp=ar[j];
          ar[j]=ar[imin];
          ar[imin]=temp;
          }
}
int main()
{
	int ar[5]={5,4,3,2,1};
	int ar_size=sizeof(ar)/sizeof(ar[0]);
	selectionsort(ar_size, ar);
	for(int i=0; i<ar_size; i++)
	{
		printf("%d\n", ar[i]);
	}

}
