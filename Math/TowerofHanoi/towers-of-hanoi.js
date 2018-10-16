'use strict';

function solveHanoi(height, srcP, desP, bufferP) {
  if (height >= 1) {
    // Move a tower of height-1 to the buffer peg, using the destination peg.
    solveHanoi(height - 1, srcP, bufferP, desP);
    // Move the remaining disk to the destination peg.
    console.log('Move disk from Tower ', srcP, ' to Tower ', desP);
    // Move the tower of `height-1` from the `buffer peg` to the `destination peg` using the `source peg`.
    solveHanoi(height - 1, bufferP, desP, srcP);
  }
  return;
}

solveHanoi(3, "A", "C", "B");
