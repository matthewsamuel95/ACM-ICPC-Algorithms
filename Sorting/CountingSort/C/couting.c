#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct read {
    int key;
    int value;
};

int findMaxValueInRange(struct read* r, int n) {
    int i;
    int max = -1;
    for(i = 0; i < n; i++) {
        if(r[i].value > max) max = r[i].value;
    }
    return max;
}

void countingSort(struct read * A, int sizeA, struct read * B, int k) {
  int i = 0;
  int *C = calloc(k+1, sizeof(int));

  for(i = 0; i < sizeA; i++){
    C[A[i].value]++;
  }
  for(i = 0; i <= k; i++) {
      C[i] = C[i] + C[i - 1];
  }

  for(i = sizeA; i > 0; i--) {
      B[C[A[i].value]] = A[i];
      C[A[i].value] = C[A[i].value] - 1;
  }
}

int main(int argc, char** argv) {
    struct read input [100001];
    struct read output [100001];
    struct read aux;
    int n = 0;
    int max = 0;
    FILE *fp;
    fp = fopen(argv[1], "r");
    if(fp != NULL) {
        while(fscanf(fp, "%d ; %d", &aux.key, &aux.value) != EOF) {
            input[n++] = aux;
        }
        max = findMaxValueInRange(input, n);
        countingSort(input, n, output, max);
    }
    return 0;
}
