package Java;

import java.util.Scanner;

public class SegmentTree {
  private final int MAX= 1000*1000;

  private final int [] originalValues = new int[MAX];
  private final int [] segmentSum = new int[MAX * 4];

  //Get sum of range [x,y] over segment [left, right] with segId
  int getSum(int segId, int left, int right, int x, int y){
    if ((y < left) || (right < x)) {
      //no intersection
      return 0;
    } else {
      //Two ranges somehow intersects.
      if ((x <= left) && (right <= y)) {
        //we need all values of [left, right]
        return segmentSum[segId];
      } else {
        //Partly intersects
        final int mid = (left+right)/2;
        //Get sum of range [x,y] over first half of segment: [left, mid]
        final int sumLeft = getSum(segId*2, left, mid, x, y);
        //Get sum of range [x,y] over second half of segment: [mid+1, right]
        final int sumRight = getSum(segId*2+1, mid+1, right, x, y);

        return sumLeft + sumRight;
      }
    }
  }

  //Update the value of p-th element, for range [left,right] with segId
  void update(int segId, int left, int right, int p, int value) {
    if (left == right) {
      //it's a node, so sum is equal to the value
      segmentSum[segId] = value;
    } else {
      final int mid = (left+right)/2;
      if(p <= mid) {
        //continue updating for only the first half of segment [left, mid]
        update(segId*2, left, mid, p, value);
      }
      else {
        //continue updating for only the second half of segment [mid+1, right]
        update(segId*2+1, mid+1, right, p, value);
      }
      //Since either half is updated, we also keep the segment updated
      segmentSum[segId] = segmentSum[segId*2] + segmentSum[segId*2+1];
    }
  }

  //Build for range [left,right]
  void build(int id, int left, int right){
    if(left == right) {
      //it's a node, so sum is equal to the element
      segmentSum[id] = originalValues[left];
    } else {
      final int mid = (left+right)/2;
      //build for range [left, mid]
      build(id*2, left, mid);
      //build for range [mid+1, right]
      build(id*2+1, mid+1, right);

      //total sum of segment id is calculated from it's two children
      segmentSum[id] = segmentSum[id*2] + segmentSum[id*2 + 1];
    }
  }

  private void run() {
    final Scanner scan = new Scanner(System.in);
    System.out.println("Please enter the number of elements and number of queries:");
    final int n = scan.nextInt();
    final int queryNum = scan.nextInt();

    System.out.println(String.format("Please enter the %d elements.",n));
    for(int i=1; i<=n; i++) {
      originalValues[i] = scan.nextInt();
    }

    //Build the tree and calculate the sums.
    build(1, 1, n);

    System.out.println(String.format("Please enter the %d queries. Op x y.",queryNum));
    System.out.println("Op=1 to get sum of interval [x,y].");
    System.out.println("Op=2 to get update value of x-th element to y.");
    for (int query=0; query < queryNum ; query+=1) {
      final int operation = scan.nextInt();
      final int x = scan.nextInt();
      final int y = scan.nextInt();
      if (operation == 1) {
        //Print the sum of segment [x,y]. We start from segment [1,n] with id=1
        System.out.println(getSum(1, 1, n, x, y));
      } else {
        //Update the value of x-th element to y.
        //We recursively update the sum starting from segment [1,n] with id=1
        update(1, 1, n, x, y);
      }
    }
  }
  /*
  Sample input:
  6 6
  3 4 1 6 3 3
  1 1 4
  1 2 5
  2 4 2
  1 4 6
  2 1 13
  1 1 6

  Sample output:
  14
  14
  8
  26
   */

  public static void main(String[] args) {
    new SegmentTree().run();
  }

}
