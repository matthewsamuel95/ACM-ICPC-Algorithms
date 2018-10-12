#include<bits/stdc++.h>
using namespace std;
int board[11][11];

bool isSafe(int col,int row,int N)
{
 int i,j;
 //check this row
 for(i=0;i<col;i++)
 {
    if(board[row][i]==1)
    return false;
     
 }
 //check the above diagonal
for(i=row,j=col;i>=0 && j>=0;i--,j--)
{
    if(board[i][j])
    return false;
    
}
//check lower diagonal
for(i=row,j=col;i<N && j>=0;i++,j--)
   { 
    if(board[i][j])
    return false;
   }
    return true;
    
}



bool solveBoard(int col,int N)
{
if(col>=N)
{

    
   return true; 
    
}



for(int i=0;i<N;i++)
{
    if(isSafe(col,i,N))
    {
        board[i][col]=1;
        
        if(solveBoard(col+1,N))
        return true;
        
        
        board[i][col]=0;
    
    }

}
    
    
    
   return false; 
    
    
    

    
}
int main()
{
int N;
cin>>N;
for(int i=0;i<N;i++)
{
    for(int j=0;j<N;j++)
    board[i][j]=0;
}


int t=solveBoard(0,N);
if(t==1)
{
    for(int i=0;i<N;i++)
{
    for(int j=0;j<N;j++)
    cout<<board[j][i]<<" ";
    
    cout<<endl;
}
}
else cout<<"Not possible\n";
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}
