/*
Given an input stream of n integers the task is to insert integers to stream and 
print the median of the new stream formed by each insertion of x to the stream.
--------------------------------------------------------------------------------
Example

Flow in stream : 5, 15, 1, 3 
5 goes to stream --> median 5 (5)
15 goes to stream --> median 10 (5, 15)
1 goes to stream --> median 5 (5, 15, 1)
3 goes to stream --> median 4 (5, 15, 1, 3)

Input:
The first line of input contains an integer N denoting the no of elements of the stream. 
Then the next N lines contains integer x denoting the no to be inserted to the stream.

Output:
For each element added to the stream print the floor of the new median in a new line.

Constraints:
1<=N<=10^5+7
1<=x<=10^5+7

Example:
Input:
4
5
15
1 
3
Output:
5
10
5
4
*/
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
 {
	public static void main (String[] args)
	 {
	 //code
	 Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        PriorityQueue<Integer> maxHeap=new PriorityQueue<Integer>(
            new Comparator<Integer> () {
                public int compare(Integer a, Integer b) {
                    return b - a;
                }   
            }    
        );
        PriorityQueue<Integer> minHeap=new PriorityQueue<Integer>();
        int first=sc.nextInt();
        int second=sc.nextInt();
        if(first<second){
            maxHeap.add(first);
            minHeap.add(second);
        }
        else{
            maxHeap.add(second);
            minHeap.add(first);
        }
        System.out.println(first);
        System.out.println(((first+second))/2);
        for(int i=0;i<n-2;i++){
            int t=sc.nextInt();
            if(t<maxHeap.peek())maxHeap.add(t);
            else minHeap.add(t);
            int diff=minHeap.size()-maxHeap.size();
            if(diff>1)maxHeap.add(minHeap.poll());
            if(diff<-1)minHeap.add(maxHeap.poll());
            diff=minHeap.size()-maxHeap.size();
            if(diff==0)System.out.println((minHeap.peek()+maxHeap.peek())/2);
            else if(diff==1)System.out.println(minHeap.peek());
            else System.out.println(maxHeap.peek());
        }
	 }
}
