#include <iostream>
#include <stdio.h>


using namespace std;

int main(void)
{
    int  i,j,ii,jj,n;
    int count=0, max_count=0, start_index=0, temp_start_index=0;
    int data[100] ;



cout<<"Input Array n : ";
cin>>n;
cout<<endl;
for(int i=1;i<=n;i++)
{

cin>>data[i];
}
cout<<endl;

    for(int i=0; i < n+1; ++i)
         {
       for (j=n;j>=0;--j)
       {
          for (ii=i,jj=j;;++ii,--jj)
          {
             if (data[ii]==data[jj])
             {
                if (count==0)
                {
                   temp_start_index=ii;
                }
                ++count;
                if (ii==jj)
                {
                    count=count*2-1;
                    break;
                }else{
                       if (ii>jj)
                       {
                          --count;
                          count=count*2;
                          break;
                       }
               }

           }

           else
           {
               count=0;
               break;
           }
       }


       if (count>max_count)
       {
           max_count=count;
           start_index=temp_start_index;
           count=0;
           temp_start_index=0;

       }
   }
 }
 cout<<"Subarray palindrom";
 cout<<endl;
  for (i=start_index;i<start_index+max_count;++i)
  {
    printf("%d ",data[i]);

  }
 }
