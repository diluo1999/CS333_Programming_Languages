/*
  CS333 Project 7
  Part II: Selected Language - Go
  Task 2
  Garbage Collection in Go

  Yixuan Qiu
  Apr 26 2020
*/

package main

import (
	"fmt"
	"time"
)

func alloc() {
	var a [][]int // create a 2D slice

	start := time.Now()

	for i := 0; i < 100; i++ {
		m := make([]int, 1024) // 'make' allocates memory
		a = append(a, m)
	}

	elapsed := time.Since(start)

	fmt.Println("Allocation took:", elapsed)
}

// main function that calls alloc() 10 times
func main() {
	for j := 0; j < 10; j++ {
		alloc()
	}
}
