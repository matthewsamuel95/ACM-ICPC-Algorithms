// This is the first lookup I have ever written, its for a BST. I was learning Data Structure implimentations in JS.
// One of my fist recursive functions aswell. How can this be improved?
  
contains(target) {
  if (target === this.value) {
    return true;
  } else if (target < this.value) {
    if (this.left === null) {
      return false;
    }
    return this.left.contains(target);
  } else if (target > this.value) {
    if (this.right === null) {
      return false;
    }
    return this.right.contains(target);
  }
}
