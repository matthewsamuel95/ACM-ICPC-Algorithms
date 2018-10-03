#include<stdio.h>

/*
 * @ar_size array size
 * @ar array pointer
 */
void bubblesort(int ar_size, int * ar) 
{
  for(int i=0; i<ar_size; i++)  
  {
  	for(int j=0; j<ar_size-i-1; j++)
  	{
  		ar[j]=ar[j]^ar[j+1];
  		ar[j+1]=ar[j]^ar[j+1];
  		ar[j]=ar[j]^ar[j+1];
  	}

  }
}
int main()
{
	int ar[5]={5,4,3,2,1};
	int ar_size=sizeof(ar)/sizeof(ar[0]);
	bubblesort(ar_size, ar);
	for(int i=0; i<ar_size; i++)
	{
		printf("%d\n", ar[i]);
	}

}
