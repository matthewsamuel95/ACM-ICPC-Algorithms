addToHeap = (heap, newMember) => {
    return [...heap, newMember];
}

heapify = (heap, currentIndex) => {
    while (true) {
        // this is heapsort algorithm in array
        // here is map function from index in arr to node in tree
        //                        1
        //                     /     \
        //                    0       1
        //                  /   \   /   \
        //                 0     1 0     1
        //          array                       tree
        //              0                          1
        //              1                         10   = 2
        //              2                         11   = 3
        //              3                        100   = 4
        //              4                        101   = 5
        //          .....                       ....
        // so the parentNode of a node is floor of (index/2)
        let parentNode = Math.floor(currentIndex / 2);
        if (parentNode !== 0) {
            // array begin with 0 and tree begin with 1 so we have to sub by 1
            if (heap[currentIndex-1] > heap[parentNode-1]) {
                [heap[currentIndex-1], heap[parentNode-1]] = [heap[parentNode-1], heap[currentIndex-1]];
                currentIndex = parentNode;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    return heap;
}

function main() {
    let arr = [10, 2, 7, 7, 9, 5, 3, 8, 1, 15];
    let ans = [];
    arr.forEach((number, index)=>{
        ans = addToHeap(ans, number);
        ans = heapify(ans, index+1);
    })
    console.log(ans);
}

main();