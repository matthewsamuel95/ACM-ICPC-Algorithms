/**
 * @author: shakeelsamsu
 * https://github.com/shakeelsamsu
 * Implementation of Binary Search in Java
 * Returns the location of element x in a given array (if present), or otherwise returns -1
 */
class BinarySearch {
    int binarysearch(int[] nums, int x) {
        int i = 0;
        int f = nums.length - 1;
        while(i <= f) {
            
            int mid = i + (f - i) / 2; //find the middle

            //check the middle
            if(nums[mid] == x) return mid;

            //if x is greater than the mid, ignore the left
            if(nums[mid] < x) i = mid + 1;
            
            //otherwise ignore the right
            else f = mid - 1;
        }

        //if we reach here, the element must not be present
        return -1;
    }

    public static void main(String[] args) {
        BinarySearch bs = new BinarySearch();
        int[] arr = {10, 2, 7, 3, 9, 15, 6};
        int n = arr.length;
        int x = 15;
        int result = bs.binarysearch(arr, x);
        if(result == - 1) System.out.println(x + " was not found");
        else System.out.println(x + " was found at index " + result);
    }
}
