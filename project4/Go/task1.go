/*
  CS333 Project 4
  Part II: Selected Language
  Go: Task 1
  Uses all control flow statements

  Yixuan Qiu
  Mar 10 2020
*/

package main

import "fmt"

func main() {
	// If statement
	if 1 != 2 {
		fmt.Println("1 is not 2")
	}

	// If with a short statement
	if n := 41; n%2 != 0 {
		fmt.Printf("%d is odd\n", n)
	}

	// If-else
	answer := 42
	if answer == 42 {
		fmt.Println("Right!")
	} else {
		fmt.Println("Wrong!")
	}

	// For Loop
	sum := 0
	for i := 0; i < 3; i++ {
		sum += i
		fmt.Printf("Sum is %d\n", sum)
	}

	// "While" loop
	sum = 1
	for sum < 10 { // equivalent to while (sum < 10) in C
		sum += sum
		fmt.Printf("Sum is %d\n", sum)
	}

	// Switch case statement
	num := 2
	switch num {
	case 0:
		fmt.Println("zero")
	case 1:
		fmt.Println("one")
	case 2:
		fmt.Println("two")
	}

	// Break statement
	for n := 1; n < 10; n++ {
		if n == 7 {
			break
		}
		fmt.Printf("n:%d\n", n)
	}

	// Continue statement
	for num := 1; num < 10; num++ {
		// skip all even numbers
		if num%2 == 0 {
			continue
		}
		// print odd numbers
		fmt.Printf("%d\n", num)
	}

	// Defer statement
	defer fmt.Println("world")
	fmt.Println("hello")

}
