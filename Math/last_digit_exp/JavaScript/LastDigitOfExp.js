/*
* Calculates the last digit of a^b
*   Args:
*     a (int): Base of a^b
*     b (int): Exponent of a^b
*   Returns:
*     (int): The last digit of a^b
*/
let last_digit_of = (a,b) => {
  let last_digit_a = parseInt(String(a).slice(-1));
  let exp;

  if (b % 4 === 0) {
    exp = 4;
  } else {
    exp = b % 4;
  }

  return (Math.pow(last_digit_a, exp) % 10)
};


/*
* Test Cases
*/
let tests = [[3,10], [6,2], [150,530]]
console.log("Tests:")
for (let array of tests) {
  console.log("last digit of " + array[0] + "^" + array [1] + " is "
             + last_digit_of(array[0], array[1]));
}
