class Stack {
  constructor () {
    this.items = []
  }
  push (item) {
    this.items.push(item)
  }
  pop () {
    if (!this.items.length) return 'Stack underflow'
    return this.items.pop()
  }
  peek () {
    return this.items[this.items.length - 1]
  }
  isEmpty () {
    return this.items.length ? 1 : 0
  }
  printStack () {
    return this.items.reduce((prev, cur) => prev + ' ' + cur)
  }
}

var stack = new Stack()
stack.push(2)
stack.push(3)
stack.push(4)
console.log(stack.printStack())
console.log(stack.isEmpty())
console.log(stack.pop())
console.log(stack.printStack())
