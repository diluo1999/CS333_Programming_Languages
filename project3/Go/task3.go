/*
  CS333 Project 3
  Part II: Selected Language
  Go: Task 3
  Demonstrates all of the basic built-in types and how to construct aggregate types (e.g., array, structs),
  demonstrates which of the standard suite of operators (+-/*%) manipulate which types
  and what the resulting type of each operation is

  Yixuan Qiu
  Mar 2 2020
*/

package main

import (
	"fmt"
	"math/cmplx"
)

// 1) basic types
var (
	boo    bool       = false
	MaxInt uint64     = 1<<64 - 1
	z      complex128 = cmplx.Sqrt(-5 + 12i)
)

// basic types test function
func testTypes() {
	fmt.Printf("Type: %T Value: %v\n", boo, boo)
	fmt.Printf("Type: %T Value: %v\n", MaxInt, MaxInt)
	fmt.Printf("Type: %T Value: %v\n\n", z, z)
}

// 2) aggregate types
// array test function
func arr() {
	var n [10]int // n is an array of 10 integers
	var i, j int

	// initialize elements of array n to 0
	for i = 0; i < 10; i++ {
		n[i] = i + 100 // set element at location i to i + 100
	}

	// output each array element's value
	for j = 0; j < 10; j++ {
		fmt.Printf("Element[%d] = %d\n", j, n[j])
	}
}

// struct
type Student struct {
	name     string
	class_yr int
	GPA      float32
}

// struct test function
func testSruct() {
	var student Student // Declare student of type Student

	// student specification
	student.name = "Gopher"
	student.class_yr = 2009
	student.GPA = 4.00

	// print student info
	fmt.Printf("\nStudent's name : %s\n", student.name)
	fmt.Printf("Student's class year : %d\n", student.class_yr)
	fmt.Printf("Student's GPA : %.2f\n\n", student.GPA)
}

// 3) operators test function
func op() {
	// a := "go"
	b := 3
	c := 5
	// fmt.Printf("%s", a+b) // invalid
	fmt.Printf("\n3 + 5 = %d\n", b+c)
	fmt.Printf("3 - 5 = %d\n", b-c)
	// fmt.Printf("%s", a*b) // invalid
	fmt.Printf("3 * 5 = %d\n", b*c)
	fmt.Printf("5 / 3 = %d\n", c/b)
}

func main() {
	testTypes() // test basic types
	arr()       // test array
	op()        // test operators
	testSruct() // test struct
}
