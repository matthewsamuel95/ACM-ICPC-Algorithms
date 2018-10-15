using System;
using System.Collections.Generic;
using System.IO;
class Solution {
    static void Main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution */
        int n = int.Parse(Console.ReadLine());
        int[] array = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
        LargestRectangle(array,n);
    }
    private static void LargestRectangle(int[] array, int n)
    {
        Stack<int> st = new Stack<int>();
        int i = 0,max_area=-1,area=0;
        while (i < n)
        {
            if (st.Count == 0 || array[st.Peek()] <= array[i])
            {
                st.Push(i);
                i++;
            }
            else
            {
                int top = array[st.Pop()];
                area = top* ((st.Count == 0) ? i : i-st.Peek()-1);
                if (area > max_area) max_area = area;
            }
        }
        while (st.Count != 0)
        {
            int top = array[st.Pop()];
            area = top * ((st.Count == 0) ? i : i - st.Peek() - 1);
            if (area > max_area) max_area = area;
        }
        Console.WriteLine(max_area);
    }
}