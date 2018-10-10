val cents = listOf(1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000)

fun minCoins(V: Int): MutableList<Int>{
    var money = V
    var solution = mutableListOf<Int>()
    for (elem in cents.sortedDescending()){
        while (money > elem){
            money -= elem
            solution.add(elem)
        }
    }
    return solution
}
fun main(args: Array<String>) {
    //Test value, should return {50000, 50000, 50000,2000,500,100,50,20,10}
    val initialValue = 152681
    print("{")
    for (elem in minCoins(initialValue)){
        print("${elem},")
    }
    print("}")
}