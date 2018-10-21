#include <iostream>
using namespace std;

void swap(int * x, int * y) {
  int temp = * x; * x = * y; * y = temp;
}

class heap {
  int heap_size;
  int * harr;
  int capacity;
  public:
    heap(int cap) {
      capacity = cap;
      heap_size = 0;
      harr = new int[cap];
    }
  int parent(int i) {
    return (i - 1) / 2;
  }
  int left(int i) {
    return (2 * i) + 1;
  }
  int right(int i) {
    return (2 * i) + 2;
  }
  void insert(int num) {
    if (heap_size == capacity) {
      cout << "Overflow" << endl;
      return;
    }
    heap_size++;
    harr[heap_size - 1] = num;
    int i = heap_size - 1;
    while (i >= 0 && harr[parent(i)] > harr[i]) {
      swap( & harr[parent(i)], & harr[i]);
      i = parent(i);
    }
  }
  void display() {
    int i;
    for (i = 0; i < heap_size; i++)
      cout << harr[i] << " ";
  }

  void minheapify(int i, int limit) {
    int l = left(i);
    int r = right(i);
    if (l >= limit || r >= limit)
      return;
    int smallest = i;
    if (harr[l] < harr[i])
      smallest = l;
    if (harr[r] < harr[smallest])
      smallest = r;
    if (i != smallest) {
      swap( & harr[i], & harr[smallest]);
      minheapify(smallest, limit);
    }
  }

  void sort() {
    int i;
    for (i = 1; i < heap_size - 1; i++) {
      swap( & harr[0], & harr[heap_size - i]);
      minheapify(0, heap_size - i);
    }
  }
};

int main() {
  heap h(10);
  h.insert(10);
  h.insert(20);
  h.insert(30);
  h.insert(12);
  h.insert(8);
  h.insert(9);
  h.insert(11);
  h.insert(13);
  h.insert(14);
  h.sort();
  h.display();
  cout << endl;
  return 0;
}
