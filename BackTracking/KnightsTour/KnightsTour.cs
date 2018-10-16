/*
move Knight in a chess board such that it covers all the cells atleast once.
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
            int[,] board = new int[8,8];
            Intialize(board);
            int[] rowx = { 2, 1, -1, -2, -2, -1, 1, 2 };
            int[] coly = { 1, 2, 2, 1, -1, -2, -2, -1 };
            if (KnightsTour(board, 0, 0, 1,rowx,coly)) Display(board);
            else Console.WriteLine("Solution does not exist");      
        }
        private static void Intialize(int[,] board)
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    board[i, j]=-1;
                }
            }
            board[0, 0] = 0;
        }
        private static void Display(int[,] board)
        {
            for(int i = 0; i < 8; i++)
            {
                for(int j = 0; j < 8; j++)
                {
                    Console.Write(board[i,j]+" ");
                }
                Console.WriteLine();
            }
        }
        private static bool KnightsTour(int[,] board, int row, int col,int move,int[] rowx,int[] coly)
        {
            if (move == 64) return true;
            int nextx, nexty;
            for(int k = 0; k < 8; k++)
            {
                nextx = row+rowx[k];
                nexty = col+coly[k];
                if (IsSafe(board, nextx, nexty))
                {
                    board[nextx, nexty] = move;
                    if(KnightsTour(board,nextx,nexty,move+1,rowx,coly))return true;
                    board[nextx, nexty] = -1;
                }
            }
            return false;
        }

        private static bool IsSafe(int[,] board, int row, int col)
        {
            if (row >= 0 && row < 8 && col >= 0 && col < 8 && board[row, col] == -1) return true;
            return false;
        }
    }
}
    