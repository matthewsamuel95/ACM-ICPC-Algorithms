// Author: Nagendra Singh

func mergeSort<T: Comparable>(_ array: [T]) -> [T] {
  guard array.count > 1 else { return array }
  let middleIndex = array.count / 2
  let leftArray = mergeSort(Array(array[0..<middleIndex]))
  let rightArray = mergeSort(Array(array[middleIndex..<array.count]))
  return merge(leftPile: leftArray, rightPile: rightArray)
}

func merge<T: Comparable>(leftPile: [T], rightPile: [T]) -> [T] {
  var leftIndex = 0
  var rightIndex = 0
  var orderedPile: [T] = []
  if orderedPile.capacity < leftPile.count + rightPile.count {
    orderedPile.reserveCapacity(leftPile.count + rightPile.count)
  }

  while true {
      guard leftIndex < leftPile.endIndex else {
          orderedPile.append(contentsOf: rightPile[rightIndex..<rightPile.endIndex])
          break
      }
      guard rightIndex < rightPile.endIndex else {
          orderedPile.append(contentsOf: leftPile[leftIndex..<leftPile.endIndex])
          break
      }
      
      if leftPile[leftIndex] < rightPile[rightIndex] {
          orderedPile.append(leftPile[leftIndex])
          leftIndex += 1
      } else {
          orderedPile.append(rightPile[rightIndex])
          rightIndex += 1
      }
  }


  return orderedPile
}
