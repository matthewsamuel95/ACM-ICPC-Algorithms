import java.util.*;

public class FourSum {

    static class Pair {
        int first, second;
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    /*
     *  Returns a list containing 4 numbers present at different indexes which sum to target. If there are multiple solutions, 
     *  return any solution.
     *  If there is no solution, return an empty list.
     */
    static List<Integer> findSubset(int[] nums, int target) {
        List<Integer> result = new ArrayList<>();
        
        // For every pair of elements, store their sum
        Map<Integer, Pair> map = new HashMap<>();
        
        int n = nums.length;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                map.put(nums[i]+nums[j], new Pair(i, j));
            }
        }
        
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                int remainingSum = target - (nums[i] + nums[j]);
                if (map.containsKey(remainingSum)) {
                    Pair  pair = map.get(remainingSum);
                    if (pair.first != i && pair.first != j && pair.second != i && pair.second != j) {
                        result.addAll(Arrays.asList(nums[i], nums[j], nums[pair.first], nums[pair.second]));
                        return result;
                    }
                }
            }
        }
        return new ArrayList<Integer>();
    }

    public static void main(String[] args) {
        int target = 23;
        int[] nums = {10, 2, 3, 4, 5, 9, 7, 8};
        List<Integer> result = findSubset(nums, target);
        if (result.size() != 4) {
            System.out.println("Four elements with the given sum not found in the array!");
        } else {
            for (int num : result) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
}