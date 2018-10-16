#include<iostream>
using namespace std;

bool subset_sum(int a[],int n, int sum)
{
       bool result[n+1][sum+1];
        /*result[i][j] stores yes,no corresponding to whether there is a subset of sum j in subarray a[0....i-1]*/
        
        int i,j;
        
        for(i=0;i<=n;i++)
        result[i][0]=true;/*always true for sum=0*/

        for(j=1;j<=sum;j++)
        result[0][j]=false;/* case of no element corresponding to non zero sum*/

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=sum;j++)
            {
                if(result[i-1][j]==true)
                result[i][j]=true;

                else
                {
                    if(a[i-1]>j)
                    result[i][j]=false;
                    else
                    result[i][j]=result[i-1][j-a[i-1]];

                }
            }}

        return result[n][sum];
}

     

    int main()
    {
        int i,n,sum;

        cout<<"Enter the value of sum"<<endl;
        cin>>sum;

        cout<<"Enter the number of elements in the set"<<endl;
        cin>>n;

        int a[n];
        cout<<"Enter the values"<<endl;
        for(i=0;i<n;i++)
            cin>>a[i];

    
        bool answer=subset_sum(a,n,sum);
        
        if(answer==true)
        cout<<"subset with the given sum exists";
        else
        cout<<"no required subset present";

        cout<<endl; 
        return 0;

    }
