import Foundation

var array = [5,3,4,6,8,2,9,1,7,10,11]
var sortedArray = NSMutableArray(array: array)

var sortedAboveIndex = array.count 
do {
    var lastSwapIndex = 0
    for ( var i = 1; i < sortedAboveIndex; i++ ) {
        if (sortedArray[i - 1].integerValue > sortedArray[i].integerValue) {
            sortedArray.exchangeObjectAtIndex(i, withObjectAtIndex: i-1)
            lastSwapIndex = i
        }
    }
    sortedAboveIndex = lastSwapIndex

} while (sortedAboveIndex != 0)

println(array)

println(sortedArray as Array)
