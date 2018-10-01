import java.util.*;
class ThreeSum
{
	public static void main(String[] ar)
	{
		//1,3,4,6,9,12
		int[] arr={12,3,4,1,6,9};
		int sum=24;
		System.out.println(checktripletSum(arr,sum));
	}
	public static boolean checktripletSum(int[] nums,int sum) {
		Arrays.sort(nums);
		int len=nums.length;
		for(int i=0;i<len-2;i++)
		{
			int start = i+1, end = len-1;
			while(start<=end)
			{
				if((nums[i]+nums[start]+nums[end])==sum)
				{
					System.out.println("The triplets are "+nums[i]+", "+nums[start]+", "+nums[end]);
					return true;
				}
				else if((nums[i]+nums[start]+nums[end])>sum)
				{
					end--;
				} 
				else
				{
					start++;
				}
			}
		}
		return false;
	}
}