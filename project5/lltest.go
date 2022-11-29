/*
  CS333 Project 5
  Part II: Selected Language - Go
  Linked list test int function

  Yixuan Qiu
  Mar 28 2020
*/

package main

import "fmt"

func main() {
	// create a list
	list := create()

	// push data on the list
	for i := 0; i < 10; i++ {
		list.push(i)
	}

	// print the list
	fmt.Println("\nAfter pushing:")
	for curr := list.head; curr != nil; curr = curr.next {
		fmt.Println(curr.data)
	}

	// test ll_map
	// .(int) convert interface{} to int
	// the map function f scales each element in list by 10
	f := func(x interface{}) interface{} { return (x.(int) * 10) }
	list.ll_map(f)

	// print the new list
	fmt.Println("\nAfter scaling by 10:")
	for curr := list.head; curr != nil; curr = curr.next {
		fmt.Println(curr.data)
	}

	// test removing data
	target := 80
	a := list.remove(target)
	if a == nil {
		fmt.Println("\nNo instance of", target)
	} else {
		fmt.Println("\nRemoved:", a)
	}

	target = 75
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
	list.append(3)
	list.append(5)

	fmt.Println("\nAfter appending:")
	for curr := list.head; curr != nil; curr = curr.next {
		fmt.Println(curr.data)
	}

	// test pop
	list.pop()
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
