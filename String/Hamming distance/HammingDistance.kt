import java.lang.Exception

fun String.calculateHammingDistance(input: String) : Int {
    if (this.length != input.length) throw Exception("Hamming distance can only be calculated between Strings of equal length.")
    var distance = 0
    this.forEachIndexed { i, c -> if (input[i] != c) distance++ }
    return distance
}

fun main(args: Array<String>) {
    println("test".calculateHammingDistance("test"))
    println("test".calculateHammingDistance("Test"))
    println("test".calculateHammingDistance("Blat"))
}