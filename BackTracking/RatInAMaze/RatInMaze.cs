/*
Consider a rat placed at (0, 0) in a square matrix m[][] of order n and has to reach the destination at (n-1, n-1).
Your task is to complete the function which returns a sorted array of strings denoting all the possible directions 
which the rat can take to reach the destination at (n-1, n-1). The directions in which the rat can move are 'U'(up), 
'D'(down), 'L' (left), 'R' (right).

For example
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1

For the above matrix the rat can reach the destination at (3, 3) from (0, 0) by two paths ie DRDDRR and DDRDRR 
when printed in sorted order we get DDRDRR DRDDRR.
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
        static void Main(String[] args)
        {
            int t = Int32.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                int n = Int32.Parse(Console.ReadLine());
                int[] rc = Array.ConvertAll(Console.ReadLine().Split(' '),Int32.Parse);
                int[,] grid = new int[n,n];
                bool[,] visited = new bool[n,n];
                for(int j = 0; j < n; j++)
                {
                    for(int k = 0; k < n; k++)
                    {
                        grid[j, k] = rc[(j*n)+k];
                    }
                }
                if (grid[0, 0] == 1) RatPuzzle(grid,visited, n, 0, 0, "");
                else Console.WriteLine("not possible");
            }
        }
        private static void RatPuzzle(int[,] grid,bool[,] visited, int n,int row,int col,string s)
        {
            visited[row, col] = true;

            if (row >= n || col >= n || row <0 || col<0) return ;
            if (row == (n - 1) && col == (n - 1))
            {
                Console.WriteLine(s+" ");
            }
            
            if ((row+1)<n && grid[row + 1, col] == 1 && !visited[row+1,col])
            {
                RatPuzzle(grid, visited, n, row + 1, col, s+"D");
            }
            if ((col - 1) >= 0 && grid[row, col - 1] == 1 && !visited[row, col - 1])
            {
                RatPuzzle(grid, visited, n, row, col - 1, s+"L");
            }
            if ((col + 1) < n && grid[row, col + 1] == 1 && !visited[row,col+1])
            {
                RatPuzzle(grid, visited, n, row, col + 1, s+"R");
            }
            if ((row-1)>=0 && grid[row-1, col] == 1 && !visited[row-1,col])
            {
                RatPuzzle(grid,visited, n, row-1, col, s+"U");
            }
            visited[row, col] = false;
        }
    }
}
    