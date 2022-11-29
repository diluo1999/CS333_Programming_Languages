/*
  CS333 Project 3
  Part II: Selected Language
  Go: Task 2
  Executes a binary search on a list or array of numbers

  Yixuan Qiu
  Mar 2 2020
*/

package main

import "fmt"

// recursive binary search
func binarySearch(list []int, key int) (result int, count int) {
	// index of the middle element in list
	mid := len(list) / 2

	switch {
	case len(list) == 0: // empty list
		result = -1 // not found

	case list[mid] > key: // search left subtree
		result, count = binarySearch(list[:mid], key)

	case list[mid] < key: // search right subtree
		result, count = binarySearch(list[mid+1:], key)
		result += mid + 1

	default: // list[mid] == key
		result = mid // found
	}

	count++
	return
}

// test function
func main() {
	list := []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29}

	// use _ to discard the index, num is a copy of the element at that index.
	for _, num := range list {
		result, count := binarySearch(list, num)
		fmt.Printf("%d found in position %d after %d steps.\n", num, result, count)
	}
}
