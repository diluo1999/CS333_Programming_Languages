/*
  CS333 Project 8
  Part II: Selected Language - Go
  Task 1
  Sort an array/slice in Go

  Yixuan Qiu
  May 10 2020
*/
package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

func merge(l, r []int) []int {
	ret := make([]int, 0, len(l)+len(r))
	for len(l) > 0 || len(r) > 0 {
		if len(l) == 0 {
			return append(ret, r...)
		}
		if len(r) == 0 {
			return append(ret, l...)
		}
		if l[0] <= r[0] {
			ret = append(ret, l[0])
			l = l[1:]
		} else {
			ret = append(ret, r[0])
			r = r[1:]
		}
	}
	return ret
}

func mergesort(s []int) []int {
	if len(s) <= 1 {
		return s
	}
	n := len(s) / 2
	l := mergesort(s[:n])
	r := mergesort(s[n:])
	return merge(l, r)
}

// parallel merge sort
func mergesortPar(s []int) []int {
	if len(s) <= 1 {
		return s
	}

	middle := len(s) / 2

	var wg sync.WaitGroup
	wg.Add(2)

	// first half
	var first []int
	go func() {
		defer wg.Done()
		first = mergesort(s[:middle])
	}()

	// second half
	var second []int
	go func() {
		defer wg.Done()
		second = mergesort(s[middle:])
	}()

	// wait for the two goroutines to complete
	wg.Wait()
	return merge(first, second)
}

func main() {
	// create a large int array
	const N = 10000
	arr := []int{}
	for i := 0; i < N; i++ {
		arr = append(arr, rand.Intn(N))
	}

	// sequential
	fmt.Println("\n---------------\nSequential:")
	fmt.Println("First 10 elements in the unsorted array:\n", arr[:10])
	start := time.Now()
	arr = mergesort(arr)
	end := time.Now()
	timeElapsed := end.Sub(start)
	fmt.Println("First 10 elements in the sorted array:\n", arr[:10])
	fmt.Printf("\nIt took %v to sort an array sequentially\n", timeElapsed)

	// repopulate the array
	for i := 0; i < N; i++ {
		arr[i] = rand.Intn(N)
	}

	// parallel
	fmt.Println("\n---------------\nParallel:")
	fmt.Println("First 10 elements in the unsorted array:\n", arr[:10])
	start = time.Now()
	arr = mergesortPar(arr)
	end = time.Now()
	timeElapsed = end.Sub(start)
	fmt.Println("First 10 elements in the sorted array:\n", arr[:10])
	fmt.Printf("\nIt took %v to sort an array parallelly\n---------------\n", timeElapsed)
}
