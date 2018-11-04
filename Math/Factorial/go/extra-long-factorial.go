package main

import (
	"fmt"
	"math/big"
)

func main() {
	var f big.Int
	var n int64

	fmt.Scanf("%d", &n)
	f.MulRange(1, n)
	fmt.Println(&f)
}
