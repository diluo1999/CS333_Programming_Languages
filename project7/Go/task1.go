/*
  CS333 Project 7
  Part II: Selected Language - Go
  Task 1
  Memory Management in Go

  Yixuan Qiu
  Apr 26 2020
*/
package main

import (
	"fmt"
)

// small struct
type smallStruct struct {
	a, b int64
	c, d float64
}

//go:noinline
func smallAllocation() *smallStruct {
	return &smallStruct{} // create memory
}

// main function that calls smallAllocation()
func main() {
	s := smallAllocation()
	fmt.Printf("s = %X\n", &s)
}
