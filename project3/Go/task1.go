/*
  CS333 Project 3
  Part II: Selected Language
  Go: Task 1
  Demonstrates the rules for identifier naming, variable declarations and identifier scoping

  Yixuan Qiu
  Mar 2 2020
*/

package main

import "fmt"

func main() {
	// 1) identifier naming

	// constant: all captial letters, _ to separate words
	const GO_LANG = "fun"

	// boolean
	var isEmpty bool
	fmt.Println(isEmpty)
	var hasConflict bool
	fmt.Println(hasConflict)

	// enum type
	type Direction string

	const (
		N Direction = "north"
		S Direction = "south"
		E Direction = "east"
		W Direction = "west"
	)

	// 2) variable declarations

	// define a variable with initial value
	var a string = "apple"
	fmt.Println(a)

	// shorthand version
	b := "book"
	fmt.Println(b)

	// define multiple variables
	var c, d int = 1, 2
	fmt.Println(c, d)

	// special variable name
	_, e := 3, 4
	fmt.Println(e)

	// 3) identifier scoping
	scope()

}

// global variable
var gbl_v string = "global"

// test scoping
func scope() {

	// Shadowing
	v := "outer"
	fmt.Println(v)
	{
		v := "inner"
		fmt.Println(v)
	}

	fmt.Println(gbl_v)
}
