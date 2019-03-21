using System;
using System.Collections.Generic;
using System.IO;
class PetrolPump
{
    public int petrolGiven;
    public int distanceToNext;
    public PetrolPump(int PetrolGiven,int DistanceToNext)
    {
        this.petrolGiven = PetrolGiven;
        this.distanceToNext = DistanceToNext;
    }
}
class Solution {
    static void Main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution */
        int n = int.Parse(Console.ReadLine());
        PetrolPump[] q = new PetrolPump[n];
        for (int i = 0; i < n; i++)
        {
            int[] info = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
            q[i]=new PetrolPump(info[0],info[1]);
        }
        TruckTour(q,n);
    }
    private static void TruckTour(PetrolPump[] q, int n)
    {
        int start = 0,end=1;
        int curr_petrol= q[start].petrolGiven- q[start].distanceToNext;
        while(curr_petrol<0 || start != end)
        {
            while(curr_petrol<0 && start != end)
            {
                curr_petrol -= (q[start].petrolGiven - q[start].distanceToNext);
                start = (start + 1) % n;
                if (start == 0)
                {
                    Console.WriteLine("Not Possible");
                    return;
                }
            }
            curr_petrol += q[end].petrolGiven - q[end].distanceToNext;
            end = (end + 1) % n;
        }
        Console.WriteLine(start);
    }
}