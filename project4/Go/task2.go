/*
  CS333 Project 4
  Part II: Selected Language
  Go: Task 2
  Shows how functions are treated in Go as a data type

  Yixuan Qiu
  Mar 8 2020
*/

package main

import (
	"fmt"
	"math"
)

// square function that takes a function as an argument
func square(sqrFunc func(num float64) float64) {
	fmt.Println("The square of 3 is:", sqrFunc(3))
}

func main() {
	// assign a function to a variable
	squareOfNum := func(num float64) float64 {
		result := math.Pow(num, 2)
		return result
	}

	// pass function as an argumnt in square function
	square(squareOfNum)
}
