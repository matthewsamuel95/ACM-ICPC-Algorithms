/*
use the below testcase to check(making job easy (formatted one)):
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace temp
{
    class Program
    {
        static void Main(String[] args)
        {
            int[,] sudoku = new int[9,9];
            for(int i = 0; i < 9; i++)
            {
                int[] row = Array.ConvertAll(Console.ReadLine().Split(' '),Int32.Parse);
                for(int j = 0; j < 9; j++)
                {
                    sudoku[i, j] = row[j];
                }
            }
            Console.WriteLine("------------------The solution is:-------------------------");
            if (solveSudoku(sudoku)) Display(sudoku);
            else Console.WriteLine("No possible solution.");
        }

        private static void Display(int[,] sudoku)
        {
            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9; j++)
                {
                    Console.Write(sudoku[i, j] + " ");
                }
                Console.WriteLine();
            }
        }

        private static bool solveSudoku(int[,] sudoku)
        {
            int[] rc = new int[2];
            if (sudokuSolved(sudoku,rc)) return true;

            for (int num = 1; num < 10; num++)
            {
                if (isSafe(sudoku, rc[0], rc[1], num))
                {
                    sudoku[rc[0], rc[1]] = num;
                    if (solveSudoku(sudoku)) return true;
                    sudoku[rc[0], rc[1]] = 0;
                }
            }
            return false;
        }

        private static bool isSafe(int[,] sudoku, int r, int c, int num)
        {
            if (notInRow(sudoku, r, num) && notInCol(sudoku, c, num) && notInGrid(sudoku, (r-(r%3)), (c-(c%3)), num)) return true;
            return false;
        }

        private static bool notInGrid(int[,] sudoku, int r, int c, int num)
        {
            for(int i = 0; i <3; i++)
            {
                for(int j = 0; j <3; j++)
                {
                    if (sudoku[i+r, j+c] == num) return false;
                }
            }
            return true;
        }
        private static bool notInCol(int[,] sudoku, int c, int num)
        {
            for(int i = 0; i < 9; i++)
            {
                if (sudoku[i, c] == num) return false;
            }
            return true;
        }

        private static bool notInRow(int[,] sudoku, int r, int num)
        {
            for (int i = 0; i < 9; i++)
            {
                if (sudoku[r, i] == num) return false;
            }
            return true;
        }

        private static bool sudokuSolved(int[,] sudoku,int[] rc)
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (sudoku[i, j] == 0)
                    {
                        rc[0] = i;
                        rc[1] = j;
                        return false;
                    }
                }
            }
            return true;
        }
    }
}
    