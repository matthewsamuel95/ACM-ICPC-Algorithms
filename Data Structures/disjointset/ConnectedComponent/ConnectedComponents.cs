/*
You are given number of nodes  N, and number of edges M of a undirected connected graph.
After adding each edge, print the size of all the connected components (in increasing order).

Input:
First line contains two integers N and M ,number of nodes and number of edges.
Next M lines contains two integers each, 
X and Y, denoting that there is an edge between X and Y.

Output:
For each edge, print the size of all the connected components (in increasing order) after adding that edge.

Constraints:
1<=N<=10^3
1<=M<=N-1
1<=X,Y<=N-1

sample input:
5 4
1 2
3 4
4 5
1 3

sample output:
1 1 1 2
1 2 2
2 3
5
*/
using System; 
using System.Numerics;
class MyClass {
static void Main(string[] args) {
    int[] nm = Array.ConvertAll(Console.ReadLine().Split(' '),Int32.Parse);
    int n = nm[0];
    int m = nm[1];
    int[] arr = new int[n];
    int[] size = new int[n];
    Intialize(arr,size,n);
    
    for(int i = 0; i < m; i++)
    {
        int[] ver= Array.ConvertAll(Console.ReadLine().Split(' '), Int32.Parse);
        WeightedUnion(arr,size,ver[0],ver[1]);
        DisplayConnected(size,n);
    }
}

    private static void DisplayConnected(int[] size, int n)
    {
        int[] temp=new int[n];
        Array.Copy(size,temp,n);
        Array.Sort(temp);
        for (int j=0; j < n; j++)
        {
            if(temp[j]>0)Console.Write(temp[j]+" ");
        }
        Console.WriteLine();
    }

    private static void WeightedUnion(int[] arr, int[] size, int a, int b)
    {
        int root_a = root(a,arr);
        int root_b = root(b,arr);
        if (arr[root_a] == arr[root_b]) return;
        else if (size[root_a] < size[root_b])
        {
            arr[root_a] = arr[root_b];
            size[root_b] += size[root_a];
            size[root_a]=0;
        }
        else
        {
            arr[root_b] = arr[root_a];
            size[root_a] += size[root_b];
            size[root_b]=0;
        }
    }

    private static int root(int a,int[] arr)
    {
        int i = a - 1;
        while (arr[i] != i)
        {
            i = arr[i];
        }
        return i;
    }

    private static void Intialize(int[] arr,int[] size,int n)
    {
        for(int i = 0; i < n; i++)
        {
            arr[i] = i;
            size[i] = 1;
        }
    }
}
