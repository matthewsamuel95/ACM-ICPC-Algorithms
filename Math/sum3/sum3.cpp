#include<iostream.h>

void main()
{

  //let the array be called a and let it have n elements 
  //let the number whose sum you want be called sum
 
 int flag=0;
  
  //the initial and final conditions of these loops are to minimize the number of repeated iterations
  //it is also to make sure that the sum for any triplet is not done more than once
  
  for (int i=0;i<n-2;i++)
    for(int j=i+1;j<n-1;j++)
      for(int k=j+1;k<n;k++)
         if(sum==(a[i]+a[j]+a[k]))
            flag=1;

   if(flag==1)
      stdio::cout<<"TRUE!!!!\n";
   else 
      stdio::cout<<"FALSE!!\n";
}
