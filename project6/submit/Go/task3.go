/*
  CS333 Project 6
  Part II: Selected Language - Go
  Task 3
  Show how Go supports error handling

  Yixuan Qiu
  Apr 18 2020
*/

package main

import (
	"errors"
	"fmt"
	"math"
)

// if the input number is NOT 42, add 1 to it
func addOne(arg int) (int, error) {
	if arg == 42 {
		// constructs a basic error value with the given error message
		return -1, errors.New("can't work with 42")
	}
	// A nil value in the error position indicates that there was no error
	return arg + 1, nil
}

func Sqrt(f float64) (float64, error) {
	if f < 0 {
		return 0, errors.New("\nError: square root of negative number")
	}
	return math.Sqrt(f), nil
}

// define a new error implementation
type NegativeSqrtError float64

func (f NegativeSqrtError) Error() string {
	return fmt.Sprintf("\nError: square root of negative number %g", float64(f))
}

func main() {

	// 1) test addOne
	for _, i := range []int{5, 42} {
		if r, e := addOne(i); e != nil {
			fmt.Println("Failed to add one to 42 -->", e)
		} else {
			fmt.Println("Added one to 5 -->", r)
		}
	}

	// 2) test NegativeSqrtError
	f, err := Sqrt(-1)
	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Println(f)
	}
}
