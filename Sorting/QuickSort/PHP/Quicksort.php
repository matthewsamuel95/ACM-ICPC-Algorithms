$unsorted = array(43,21,2,1,9,24,2,99,23,8,7,114,92,5);

function quick_sort($array)
{
	// find array size
	$length = count($array);
	
	// base case test, if array of length 0 then just return array to caller
	if($length <= 1){
		return $array;
	}
	else{
	
		// select an item to act as our pivot point, since list is unsorted first position is easiest
		$pivot = $array[0];
		
		// declare our two arrays to act as partitions
		$left = $right = array();
		
		// loop and compare each item in the array to the pivot value, place item in appropriate partition
		for($i = 1; $i < count($array); $i++)
		{
			if($array[$i] < $pivot){
				$left[] = $array[$i];
			}
			else{
				$right[] = $array[$i];
			}
		}
		
		// use recursion to now sort the left and right lists
		return array_merge(quick_sort($left), array($pivot), quick_sort($right));
	}
}

$sorted = quick_sort($unsorted);
print_r($sorted);