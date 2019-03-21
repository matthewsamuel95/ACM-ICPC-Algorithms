package main

import (
	"fmt"
)

func main() {
	a := []int{5, 109, 87, 4, 50, 908, 65, 22, 1, 36}
	a = heapsort(a)
	fmt.Println(a)
}

func heapsort(a []int) []int {
	heapify(a, len(a))
	end := len(a) - 1
	for end > 0 {
		a[end], a[0] = a[0], a[end]
		end--
		traverse(a, 0, end)
	}
	return a
}

func heapify(a []int, count int) {
	start := int((count - 2) / 2)
	for start >= 0 {
		traverse(a, start, count-1)
		start--
	}

}

func traverse(a []int, start, end int) {
	root := start
	for (root*2 + 1) <= end {
		child := root*2 + 1
		swap := root
		if a[swap] < a[child] {
			swap = child
		}
		if (child+1) <= end && a[swap] < a[child+1] {
			swap = child + 1
		}
		if swap != root {
			a[root], a[swap] = a[swap], a[root]
			root = swap
		} else {
			return
		}
	}
}
