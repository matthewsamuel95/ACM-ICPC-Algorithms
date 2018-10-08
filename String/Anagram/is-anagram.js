function isAnagram(str1, str2) {
  return regularize(str1) === regularize(str2);
}

function regularize(str) {
  return str.replace(/[^a-z\d]/g,'').toLowerCase().split('').sort().join('');
}

// console.log(isAnagram('santa', 'satan')); => true
// console.log(isAnagram('santa', 'santana')); => false
