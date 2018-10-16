/*
Monk is having a hard time teaching the 2nd standard students.
He wants to divide the students into small groups so that he can conduct 
some fun-filled activities for them. But students also want their friends in the same group. So, if student 
A is a friend of student B, and student B is a friend of student C, then the students 
A,B and C must be in the same group, otherwise they will start crying.
After dividing the students, he will choose a leader from each group who will lead their respective groups. 
Now he wants to know the number of ways he can choose the group leaders from all the groups.
Print this answer modulo 10^9+7.

Note: Two ways A and B will be considered different if at least 1 person is a leader in group A,
and is not a leader in group B, or vice-versa.

Input:
The first line consists of two integers N and M denoting the number of students and the number of relationships respectively.
The next M lines consists of two integers 
u and v denoting that student u and student v are friends. 
u and v can never be equal and relationships are not repeated.

output:
Print the answer modulo 10^9+7 in a single line.
*/
using System; 
using System.Numerics;
class MyClass {
    static void Main(string[] args)
    {
        int[] _nm= Array.ConvertAll(Console.ReadLine().Split(' '), Int32.Parse);
        int n = _nm[0];
        int m = _nm[1];

        int[] students = new int[n];
        long[] size = new long[n];
        Initialize(students,size,n);
        for(int i = 0; i < m; i++)
        {
            int[] ver= Array.ConvertAll(Console.ReadLine().Split(' '), Int32.Parse);
            WeightedUnion(students,size,ver[0]-1,ver[1]-1);
        }
        long product = 1;
        for(int i = 0; i < n; i++)
        {
            if (size[i] != 0) product *= size[i];
            product %= (long)(Math.Pow(10, 9) + 7);
        }
        Console.WriteLine(product);
    }
    private static void WeightedUnion(int[] students, long[] size, int a, int b)
    {
        int root_a = root(a,students);
        int root_b = root(b,students);
        if (students[root_a] == students[root_b]) return;
        else if (size[root_a] < size[root_b])
        {
            students[root_a] = students[root_b];
            size[root_b] += size[root_a];
            size[root_a]=0;
        }
        else
        {
            students[root_b] = students[root_a];
            size[root_a] += size[root_b];
            size[root_b] = 0;
        }
    }
    private static int root(int v, int[] students)
    {
        int i = v;
        while (students[i] != i)
        {
            i = students[i];
        }
        return i;
    }
    private static void Initialize(int[] students, long[] size, int n)
    {
        for(int i = 0; i < n; i++)
        {
            students[i] = i;
            size[i] = 1;
        }
    }
}
