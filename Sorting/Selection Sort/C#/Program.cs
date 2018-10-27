using System;
using System.Collections;
using System.Collections.Generic;

namespace Algorithms
{
    class Sort
    {
        static void Selection(int[] numbers)
        {
            for (int i = 0; i < numbers.Length - 1; i++)
            {
                int minIndex = i;

                for (int j = i + 1; j < numbers.Length; j++)
                {
                    if (numbers[j] < numbers[minIndex]) minIndex = j;
                }

                if (minIndex != i)
                { 
                    Swap(ref numbers[minIndex], ref numbers[i]);
                }
            }
        }

        static void Swap(ref int a, ref int b)
        {
            int temp = a;
            a = b;
            b = temp;
        }        

        static void Main(string[] args)
        {
            int[] numbers = {5, 1, 7, 6, -4, 30, 2};

            Selection(numbers);

            foreach (int item in numbers)
            {
                Console.WriteLine(item.ToString());
            }
        }
    }
}