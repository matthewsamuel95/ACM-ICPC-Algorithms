/* ** Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which
 minimizes the sum of all numbers along its path
 * **/

 /* ** Complexity of Program O(m*n), where m is number of rows and n is number of columns of matrix ** */

 /* Coded in C++14 */

#include<iostream>
using namespace std;

int Min(int a,int b,int c)
{
    if(a<=b && a<=c)
    {
        return a;
    }
    else if(b<=a&& b<=c)
    {
        return b;
    }
    else
    {
        return c;
    }
}

int main()
{
    cout<<"\n Enter number of rows of matrix : ";
    int m;
    cin>>m;
    cout<<"\n Enter number of columns of matrix : ";
    int n;
    cin>>n;
    int Matrix[m][n];
    for(int i=0;i<m;i++)
    {
        cout<<"\nEnter "<<n<<" elements of row "<<i+1<<" seprated by space\n";
        for(int j=0;j<n;j++)
        {
            cin>>Matrix[i][j];
        }
    }

    int CostMatrix[m][n];
    
    //Base Condition
    CostMatrix[0][0]=Matrix[0][0];

    //Initializing First Row
    for(int i=1;i<n;i++)
    {
        CostMatrix[0][i]=CostMatrix[0][i-1]+Matrix[0][i];
    }

    //Initializing First Column
    for(int i=1;i<m;i++)
    {
        CostMatrix[i][0]=CostMatrix[i-1][0]+Matrix[i][0];
    }

    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            CostMatrix[i][j]=(Min(CostMatrix[i-1][j-1],CostMatrix[i-1][j],CostMatrix[i][j-1]))+Matrix[i][j];
        }
    }
    cout<<"\n Minimum Sum Of Path is : "<<CostMatrix[m-1][n-1];
    return 0;
}
