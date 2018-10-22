/**
  Recursive implementation of Binary Search
  */

object BinarySearch {

  /**
   * Returns the index of the key in the given array if found,
   * otherwise returns -1.
   */
  def search(arr: Array[Int], l: Int, r: Int, key: Int): Int = {
    if (l <= r) {
      val mid = l + (r - l) / 2
      if (key == arr(mid))
        mid
      else if (key < arr(mid))
        search(arr, l, mid - 1, key)
      else
        search(arr, mid + 1, r, key)
    } else -1
  }

  def main(args: Array[String]): Unit = {
    val sortedArray: Array[Int] = Array(10, 20, 30, 40, 50, 60, 70, 80, 90)
    val (l, r): (Int, Int) = (0, sortedArray.length - 1)
    val key: Int = 50
    val result: Int = search(sortedArray, 0, sortedArray.length - 1, key)

    if (result == -1)
      println(s"$key is not found in the array!")
    else
      println(s"$key is found at index $result.")
  }
}