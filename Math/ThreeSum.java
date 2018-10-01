import java.util.*;
class ThreeSum
{
	public static void main(String[] ar)
	{
		int[] arr={1,2,3,2,2,2,1,12,1};
		System.out.println(containsDuplicate(arr));
	}
	public static boolean containsDuplicate(int[] nums) {
		Set set = new HashSet();
		for(int i : nums)
			if(!set.add(i))
				return true;
	return false;
	}
}