/**
 * CS333 Project 2
 * Part II: Selected Language
 * Go: Task 4
 * A "hello world" program
 *
 * Yixuan Qiu
 * Feb 26 2020
 */

package main

import "fmt"

func main() {
	// 1) Print “Hello, World!” to console
	fmt.Printf("Hello, world!\n")

	// 2) String concatenation
	fmt.Println("I " + "love " + "Go!")

	// 3) Arithmetic operation
	fmt.Println("1 + 2 =", 1+2)
	fmt.Println("9 - 20 =", 9-20)
	fmt.Println("7 * 9 =", 7*9)
	fmt.Println("6 / 3 =", 6/3)

	// 4) Boolean operation
	fmt.Println("true AND false is: ", true && false)
	fmt.Println("true OR false is: ", true || false)
	fmt.Println("NOT true is: ", !true)

	// 5) Capture user input
	fmt.Println("Please enter your name.") // print text to the screen
	var name string                        // create a new string variable using the var keyword
	fmt.Scanln(&name)                      // tells the computer to wait for input from the keyboard
	fmt.Printf("Hi, %s! I'm Go!\n", name)  // takes a string and injects the value of name into the string
}
