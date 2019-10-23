/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, print all distinct solutions to the n-queens puzzle.
Each solution contains distinct board configurations of the n-queens’ placement,
where the solutions are a permutation of [1,2,3..n] in increasing order,
here the number in the ith place denotes that the ith-column queen is placed in the row with that number.
For eg below figure represents a chessboard [3 1 4 2].
[0,0,Q,0]
[Q,0,0,0]
[0,0,0,Q]
[0,Q,0,0]
Input:
The first line of input contains an integer T denoting the no of test cases.
Then T test cases follow. Each test case contains an integer n denoting the size of the chessboard.

Output:
For each test case, output your solutions on one line where each solution is enclosed in square brackets 
'[', ']' separated by a space . The solutions are permutations of {1, 2, 3 …, n} in increasing order where 
the number in the ith place denotes the ith-column queen is placed in the row with that number, 
if no solution exists print -1.

Constraints:
1<=T<=10
1<=n<=10

Example:
Input
2
1
4
Output:
[1 ]
[2 4 1 3 ] [3 1 4 2 ]
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GFG
{
    class Program
    {
        static bool resultFound=false; 
        static void Main(String[] args)
        {
            int t = Int32.Parse(Console.ReadLine());
            for(int i = 0; i < t; i++)
            {
                int n= Int32.Parse(Console.ReadLine());
                int[,] board = new int[n,n];
                Nqueen(board,0,n);
                if (!resultFound) Console.Write(-1);
                Console.WriteLine();
            }   
        }
        private static void Display(int[,] board, int n)
        {
            Console.Write("[");
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if (board[j, i] == 1)Console.Write(j + 1+" ");
                }
            }
            Console.Write("]");
        }
        private static void Nqueen(int[,] board, int col, int n)
        {
            if (col >= n)
            {
                resultFound = true;
                Display(board,n);
                return;
            }
            for(int i = 0; i < n; i++)
            {
                if (IsSafe(board, i, col, n))
                {
                    board[i, col] = 1;
                    Nqueen(board, col + 1, n);
                    board[i, col] = 0;
                }
            }
        }
        private static bool IsSafe(int[,] board, int row, int col, int n)
        {
            for(int i = 0; i < col; i++)
            {
                if (board[row, i] == 1) return false;
            }
            for(int i=row,j=col;i>=0 && j >=0; i--, j--)
            {
                if (board[i, j] == 1) return false;
            }
            for(int i=row,j=col;i<n && j >= 0; i++, j--)
            {
                if (board[i, j] == 1) return false;
            }
            return true;
        }
    }
}
    