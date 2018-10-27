function isPowerOfTwo(number) {
  return (number && !(number & (number - 1)))
}

var number = 64 // Replace it with your number

if(isPowerOfTwo(number)) console.log(`The number ${number} is a power of TWO`)
else console.log(`The number ${number} is NOT a power of TWO`)
