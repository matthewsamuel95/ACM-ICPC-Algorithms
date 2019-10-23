// Quick sort program in kotlin
import java.util.*
object QuickSort {
    private fun sort(arr: IntArray) {
        quickSort(arr, 0, arr.size - 1)
    }

    /**
     * function to quick sort
     */
    private fun quickSort(arr: IntArray, low: Int, high: Int) {
        var i = low
        var j = high
        var temp: Int
        val pivot = arr[(low + high) / 2]

        // divide
        while (i <= j) {
            while (arr[i] < pivot)
                i++
            while (arr[j] > pivot)
                j--
            if (i <= j) {
                temp = arr[i]
                arr[i] = arr[j]
                arr[j] = temp
                i++
                j--
            }
        }

        // sort lower half
        if (low < j)
            quickSort(arr, low, j)
        // sort upper half
        if (i < high)
            quickSort(arr, i, high)
    }

    /**
     * Main method
     */
    @JvmStatic
    fun main(args: Array<String>) {
        val scan = Scanner(System.`in`)
        println("Quick Sort\n")
        val n: Int
        var i = 0
        print("Enter size of integer array : ")
        n = scan.nextInt()
        val arr = IntArray(n)
        println("\nEnter $n elements : ")
        while (i < n) {
            arr[i] = scan.nextInt()
            i++
        }
        // Call method sort
        sort(arr)
        // Print sorted Array
        print("\nSorted Array : ")
        i = 0
        while (i < n) {
            print(arr[i].toString() + " ")
            i++
        }
        println()
    }
}