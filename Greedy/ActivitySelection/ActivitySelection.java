/*
Given N activities with their start and finish times. 
Select the maximum number of activities that can be performed by a single person, 
assuming that a person can only work on a single activity at a time.

Note : The start time and end time of two activities may coincide.

Input:
The first line contains T denoting the number of testcases. 
Then follows description of testcases. First line is N number of activities 
then second line contains N numbers which are starting time of activies.
Third line contains N finishing time of activities.
 
Output:
For each test case, output a single number denoting maximum activites which can be performed in new line.
 

Constraints:
1<=T<=50
1<=N<=1000
1<=A[i]<=100
 

Example:
Input:
1
6
1 3 0 5 8 5
2 4 6 7 9 9

Output:
4
*/
import java.util.*;
import java.lang.*;
import java.io.*;
class Activity implements Comparable<Activity>{
    int startTime;
    int endTime;
    Activity(int start,int end){
        this.startTime=start;
        this.endTime=end;
    }
    public int compareTo(Activity a){  
          return this.endTime-a.endTime;
    }  
}
class GFG
{
	public static void main (String[] args)
	{
	    //code
	    Scanner sc=new Scanner(System.in);
	    int t=sc.nextInt();
	    for(int i=0;i<t;i++){
	        ArrayList<Activity> al=new ArrayList<Activity>();
	        int n=sc.nextInt(),temp;
	        int[] startAr=new int[n];
	        for(int j=0;j<n;j++){
	            startAr[j]=sc.nextInt();
	        }
	        for(int j=0;j<n;j++){
	            temp=sc.nextInt();
	            al.add(new Activity(startAr[j],temp));
	        }
	        Collections.sort(al);
	        ActivityProblem(al,n);
	    }
	}
	private static void ActivityProblem(ArrayList<Activity> al,int n){
	    Activity prev=al.get(0),curr;
	    int count=1;
	    for(int i=1;i<n;i++){
	       curr=al.get(i);
	       if(prev.endTime<=curr.startTime){
	           count++;
	           prev=curr;
	       }
	    }
	    System.out.println(count);
	}
}