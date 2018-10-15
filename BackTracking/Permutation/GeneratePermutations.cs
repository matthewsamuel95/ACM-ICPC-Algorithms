/*
sb=abc

output:
abc
acb
bac
bca
cba
cab
*/
using System;
using System.Text;

namespace Hackerearth
{
    class Program
    {
        static void Main(string[] args)
        {
            StringBuilder sb = new StringBuilder(Console.ReadLine());
            int n = sb.Length;
            GeneratePermutations(sb,0,n-1);
        }
        private static void GeneratePermutations(StringBuilder sb, int l,int r)
        {
            if (l == r) Console.WriteLine(sb);
            for (int i = l; i <= r; i++)
            {
                swap(sb, l,i);
                GeneratePermutations(sb,l+1,r);
                swap(sb,l,i);
            }
            
        }
        private static void swap(StringBuilder sb, int i, int j)
        {
            char temp = sb[i];
            sb[i] = sb[j];
            sb[j] = temp;
        }
    }
}
