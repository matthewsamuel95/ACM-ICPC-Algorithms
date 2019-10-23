/*
The arrays need to be sorted first, either as ascending or descending. But on this example, we use ascending one.
 */

var arrays = [4,16,20,26,30,50,80];
var binary_search = find_variable => {

  let head = 0
  let rule = arrays.length -1

  while(head <= rule){

    let middle = head + (rule - head) / 2;

    if(arrays[middle] == find_variable)
      return middle

    else if(arrays[middle] < find_variable)
      head = middle + 1

    else
      rule = middle - 1
  }

  return "it's not exist"
}

console.log(binary_search(4))
console.log(binary_search(70))
