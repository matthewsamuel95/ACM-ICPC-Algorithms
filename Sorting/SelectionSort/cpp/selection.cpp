#include<iostream>
#include<conio.h>

using namespace std;


template <class T>
void s_sort(T a[],int n)
{
     int i,j,t;
     for(i=0;i<n;i++)
     {
                     for(j=i+1;j<n;j++)
                     {
                                       if(a[j]<a[i]) //for descending order use if(a[j]>a[i]) 
                                       {
                                                    t=a[i];
                                                    a[i]=a[j];
                                                    a[j]=t;
                                       }
                     }
     }
}


int main()
{
    int a[100],i,n;
    cout<<"Enter The number of Element:\n";
    cin>>n;
    cout<<"\nEnter Elements:\n";
    for(i=0;i<n;i++)
    {

                      cout<<"\nEnter:";
                    cin>>a[i];
    }
    s_sort(a,n);
    cout<<"\nAfter Sorting\n";
    for(i=0;i<n;i++)
    {
                    cout<<a[i]<<"\t";
    }
    getch();
    return 0;
}
