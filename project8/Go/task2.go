/*
  CS333 Project 8
  Part II: Selected Language - Go
  Task 2
  Convert an image to grayscale

  Yixuan Qiu
  May 10 2020
*/
package main

import (
	"image"
	"image/jpeg"
	"log"
	"os"
	"sync"
)

// set the value of each element in slice a with v
func set(wg *sync.WaitGroup, a []uint8, v uint8) {
	for i := 0; i < len(a); i++ {
		a[i] = v
	}
	wg.Done() // call Done within a goroutine to signal the end of its’ execution
}

// convert image to grayscale
func gray(i *image.YCbCr) {
	var wg sync.WaitGroup
	wg.Add(2) // set the number of goroutines we want to wait for

	go set(&wg, i.Cb, 128)
	go set(&wg, i.Cr, 128)

	// block the execution of main()
	// until the goroutines in the waitgroup have completed
	wg.Wait()
}

func main() {
	// open an image file and read
	file, err := os.Open("IMG_7564.jpeg")
	i, err := jpeg.Decode(file)
	if err != nil {
		log.Fatalf("decoding image: %v", err)
	}

	gray(i.(*image.YCbCr))

	// write to a file
	output, err := os.Create("grayscale.jpeg")
	err = jpeg.Encode(output, i, nil)
	if err != nil {
		log.Fatalf("encoding image: %v", err)
	}
}
