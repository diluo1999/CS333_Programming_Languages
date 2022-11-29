/*
  CS333 Project 5
  Part II: Selected Language - Go
  Linked list test string function

  Yixuan Qiu
  Mar 28 2020
*/

package main

import "fmt"

func main() {
	// create a list
	list := create()

	// push data on the list
	list.push("two")
	list.push("three")
	list.push("four")

	// print the list
	fmt.Println("\nAfter pushing:")
	for curr := list.head; curr != nil; curr = curr.next {
		fmt.Println(curr.data)
	}

	// test ll_map
	// .(string) convert interface{} to string
	// the map function f concatenates the given string with " apples"
	f := func(x interface{}) interface{} { return x.(string) + " apples" }
	list.ll_map(f)

	// print the new list
	fmt.Println("\nAfter string concatenation:")
	for curr := list.head; curr != nil; curr = curr.next {
		fmt.Println(curr.data)
	}

	// test removing data
	target := "two apples"
	a := list.remove(target)
	if a == nil {
		fmt.Println("\nNo instance of", target)
	} else {
		fmt.Println("\nRemoved:", a)
	}

	target = "one apple"
	a = list.remove(target)
	if a == nil {
		fmt.Println("\nNo instance of", target)
	} else {
		fmt.Println("\nRemoved:", a)
	}

	fmt.Println("\nAfter removals:")
	for curr := list.head; curr != nil; curr = curr.next {
		fmt.Println(curr.data)
	}

	// test appending data
	list.append("five oranges")
	list.append("six pears")

	fmt.Println("\nAfter appending:")
	for curr := list.head; curr != nil; curr = curr.next {
		fmt.Println(curr.data)
	}

	// test pop
	list.pop()
	list.pop()

	fmt.Println("\nAfter poping:")
	for curr := list.head; curr != nil; curr = curr.next {
		fmt.Println(curr.data)
	}
	fmt.Println("\nSize:", list.size)

	// test clearing
	list.removeAll()
	fmt.Println("\nAfter clearing:")
	for curr := list.head; curr != nil; curr = curr.next {
		fmt.Println(curr.data)
	}
	fmt.Println("\nSize:", list.size)

}
