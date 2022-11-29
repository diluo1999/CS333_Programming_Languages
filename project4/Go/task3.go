/*
  CS333 Project 4
  Part II: Selected Language
  Go: Task 3
  Implement a general quicksort algorithm

  Yixuan Qiu
  Mar 11 2020
*/

package main

import (
	"fmt"
	"sort"
)

// takes last element as pivot, places pivot element at correct position in sorted array,
// and places elements smaller than pivot to left of pivot and elements larger than pivot to right of pivot
func partition(a sort.Interface, low int, high int, asc bool) int {
	pivot := high // set pivot to be index of last element
	i := low      // index of smaller element

	// j: index of current element
	for j := low; j < high; j++ {
		// if sort in ascending order
		if asc {
			if a.Less(j, pivot) { // if current element smaller than pivot
				a.Swap(i, j) // swap elements at indices i and j
				i++          // increment i
			}
		} else {
			// else sort in descending order
			if a.Less(j, pivot) == false { // if current element larger than pivot
				a.Swap(i, j) // swap elements at indices i and j
				i++          // increment i
			}
		}

	}

	a.Swap(i, high)
	return i
}

func quicksort(a sort.Interface, low int, high int, asc bool) {
	if low >= high {
		return
	}
	pivot := partition(a, low, high, asc) // pivot is partitioning index
	quicksort(a, low, pivot-1, asc)       // recursively sort elements to the left of the pivot
	quicksort(a, pivot+1, high, asc)      // recursively sort elements to the right of the pivot
}

func main() {
	// sort int array
	a := []int{11, 1, 5, 17, 2, 3, 7}
	fmt.Printf("Unsorted: %v\n", a)
	// asc = true, sort in ascending order
	quicksort(sort.IntSlice(a), 0, sort.IntSlice(a).Len()-1, true)
	fmt.Printf("Sorted in ascending order: %v\n", a)
	// asc = false, sort in descending order
	quicksort(sort.IntSlice(a), 0, sort.IntSlice(a).Len()-1, false)
	fmt.Printf("Sorted in descending order: %v\n", a)

	// sort string array
	b := []string{"apples", "grapes", "bananas", "pears", "blueberries", "oranges", "mangos"}
	fmt.Printf("Unsorted: %v\n", b)
	quicksort(sort.StringSlice(b), 0, sort.IntSlice(a).Len()-1, true)
	fmt.Printf("Sorted in ascending order: %v\n", b)
	quicksort(sort.StringSlice(b), 0, sort.IntSlice(a).Len()-1, false)
	fmt.Printf("Sorted in descending order: %v\n", b)
}
