fun main(args: Array<String>) {
    val data = listOf(2, 7, 90, 6, 54, 8, 34, 16)
    val x = 16

    println(data.sorted().binarySearch(x))
}
