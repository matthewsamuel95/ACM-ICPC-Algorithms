function factorial(number) {
  if(number < 0) {
    return "Negative numbers aren't allowed"
  }
  if(number % 1 !== 0) {
    return "Non Integer numbers aren't allowed"
  }

  function compute(number) {
    if(number === 0 || number === 1) return 1
    return (number * compute(number -1))
  }
  return compute(number)
}

console.log(factorial(5))
