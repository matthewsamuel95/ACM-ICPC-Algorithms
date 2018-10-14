package main

fun main(args: Array<String>) {  
   	var num = 9
    var isPrime = checkPrimeNumber(num)
    if (isPrime)
        println("$num is a prime number.")
    else
        println("$num is not a prime number.")
}

fun checkPrimeNumber(num: Int): Boolean {
    var flag = true
    if (num == 1) return false
    for (i in 2..num / 2) {
        if (num % i == 0) {
            flag = false
            break
        }
    }

    return flag
}