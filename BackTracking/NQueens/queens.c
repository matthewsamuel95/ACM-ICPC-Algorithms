#include <stdio.h>

//Size of chess board
int N;

//chessboard
char board[100][100];

//function to check if the cell is attacked or not
int is_attack(int i,int j)
{
    int k,l;
    //checking if there is a queen in row or column
    for(k=0;k<N;k++)
    {
        if((board[i][k] == '?') || (board[k][j] == '?'))
            return 1;
    }
    //checking for diagonals
    for(k=0;k<N;k++)
    {
        for(l=0;l<N;l++)
        {
            if(((k+l) == (i+j)) || ((k-l) == (i-j)))
            {
                if(board[k][l] == '?')
                    return 1;
            }
        }
    }
    return 0;
}

int N_queen(int q)
{   
    //if no. of queens are greater than No. of rows
    if (q>N)
        return 0;


    int i,j;
    //if Q is 0, solution found
    if(q==0)
        return 1;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            //checking if we can place a queen here or not
            //queen will not be placed if the place is being attacked
            //or already occupied
            if((!is_attack(i,j)) && (board[i][j]!='?'))
            {
                board[i][j] = '?';
                //recursion
                //wether we can put the next queen with this arrangment or not
                if(N_queen(q-1)==1)
                {
                    return 1;
                }
                board[i][j] = '*';
            }
        }
    }
    return 0;
}

int main()
{
    int Q;
    //taking the value of N
    printf("Enter the value of N for NxN chessboard\n");
    scanf("%d",&N);
    printf("Enter value No. of queens\n");
    scanf("%d",&Q);

    int i,j;
    //setting all elements to '*'s
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            board[i][j]='*';
        }
    }
    //calling the function
    N_queen(Q);

    //printing the matix
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%c ",board[i][j]);
        printf("\n");
    }
    return 0;
}
