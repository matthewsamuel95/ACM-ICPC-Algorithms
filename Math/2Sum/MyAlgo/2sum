public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        
        HashMap<Integer,Integer> hash = new HashMap<Integer,Integer>();
        for(int i = 0; i < numbers.length; i++){

            Integer diff = (Integer)(target - numbers[i]);
            if(hash.containsKey(diff)){
                int toReturn[] = {hash.get(diff)+1, i+1};
                return toReturn;
            }

            hash.put(numbers[i], i);

        }
        
        return null;
        
    }
}
