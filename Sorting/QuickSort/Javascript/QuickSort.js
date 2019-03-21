function quick_Sort(origArray) {
	if (origArray.length<=1) 
    { 
		return origArray;
	} 
    else 
    {
        var left=[],right=[],newArray=[];
		var pivot=origArray.pop();
		var length=origArray.length;

		for (var i=0; i<length ;++i) 
        {
			if (origArray[i]<=pivot) 
            {
				left.push(origArray[i]);
			}
            else 
            {
				right.push(origArray[i]);
			}
		}

		return newArray.concat(quick_Sort(left), pivot, quick_Sort(right));
	}
}

var myArray = [3,3,-1, 0, 2, 5, -1, 4, 1 ];

console.log("Original array: " + myArray);  //3,3,-1,0,2,5,-1,4,1

var sortedArray = quick_Sort(myArray);

console.log("Sorted array: " + sortedArray);    //-1,-1,0,1,2,3,3,4,5
