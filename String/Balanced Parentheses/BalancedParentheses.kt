import java.util.*

fun String.isBalanced(): Boolean {
    val charStack = Stack<Char>()
    this.forEach {
        when (it) {
            '(', '{', '[' -> charStack.push(it)
            ')' -> if (charStack.peek() == '(') charStack.pop() else return false
            '}' -> if (charStack.peek() == '{') charStack.pop() else return false
            ']' -> if (charStack.peek() == '[') charStack.pop() else return false
        }
    }
    return charStack.size == 0
}

fun main(args: Array<String>) {
    println(("()()((()))".isBalanced()))
    println(("()()((({)))".isBalanced()))
    println(("()()([(({}))])".isBalanced()))
}