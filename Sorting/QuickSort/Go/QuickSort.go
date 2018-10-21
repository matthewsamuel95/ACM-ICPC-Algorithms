package main

import (
	"math/rand"
	"fmt"
)

func QuickSort(slice []int) []int {
	if len(slice) <= 1 {
		return slice
	}
	left, right := 0, len(slice) - 1

	m := rand.Intn(len(slice))
	slice[m], slice[right] = slice[right], slice[m]

	for i := range slice {
		if slice[i] < slice[right] {
			slice[i], slice[left] = slice[left], slice[i]
			left++
		}
	}

	slice[left], slice[right] = slice[right], slice[left]

	QuickSort(slice[:left])
	QuickSort(slice[left + 1:])

	return slice
}

func main() {
	slice := []int{43, 41, 82, 2, 16, 7}
	fmt.Println(slice)
	fmt.Println(QuickSort(slice))
}
