#include <iostream>
using namespace std;

// Returns n choose r. (i.e. The number of distinct sets of size k chosen from n items). [O(r)]
// Note that C(n, r) = C(n, n - r)
// So call the function with nCr(n, min(r, n-r)) for better performance.
int nCr(int n, int r) {
    if (n < r)
        return 0;

    if (r == 0)
        return 1;

    return n * nCr(n - 1, r - 1) / r;
}

int main(int argc, char** argv){

    if(argc != 3){
        cerr<<"Usage: nCr n r\nWhere n is the number of all items and r is the number of chosen sets.";
        return 1;
    }
    int n = atoi(argv[1]), r = atoi(argv[2]);
    printf("%d choose %d = %d\n", n, r, nCr(n,r));

    return 0;
}
