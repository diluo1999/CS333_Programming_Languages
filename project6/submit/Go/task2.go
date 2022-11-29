/*
  CS333 Project 6
  Part II: Selected Language - Go
  Task 2
  Show how Go reads from and writes to a file

  Yixuan Qiu
  Apr 18 2020
*/

package main

import (
	"fmt"
	"io"
	"io/ioutil"
	"log"
	"net/http"
	"os"
)

// check errors
func check(e error) {
	if e != nil {
		panic(e)
	}
}

func main() {
	// 1) open, close, and read from a file
	// open a file
	f, err := os.Open("dat1") // support for binary file
	if err != nil {
		fmt.Println(err)
		return
	}

	// close a file
	defer f.Close()

	// allow up to 4096 bytes to be read
	data := make([]byte, 4096)
	for {
		data = data[:cap(data)]
		// 2) io.Reader interface's Read method
		n, err := f.Read(data)
		if err != nil {
			if err == io.EOF {
				break
			}
			fmt.Println(err)
			return
		}
		data = data[:n]
	}

	// write a string into a file
	d1 := []byte("hello\ngo\n")
	err := ioutil.WriteFile("dat1", d1, 0644)
	check(err)
	// check the content of the written file in terminal:
	// cat dat1

	// 3) open file URL
	response, err := http.Get("https://raw.githubusercontent.com/qiuyixuan/CS333/master/test.txt")

	if err != nil {
		fmt.Println(err)
		return
	}

	defer response.Body.Close()

	// Copy data from the response to standard output
	n, err1 := io.Copy(os.Stdout, response.Body) //use package "io" and "os"
	if err != nil {
		fmt.Println(err1)
		return
	}

	fmt.Println("\nNumber of bytes:", n)

	// open a file on the local disk
	file, err := os.Open("test.txt")
	// if an error occurs
	if err != nil {
		// call log.Fatal to print the error message and stop
		log.Fatal(err)
	}
	defer file.Close()
	b, err := ioutil.ReadAll(file)
	fmt.Print("Content of file:\n", string(b), "\n")

	// 4) user input information into the program interactively
	// Read integer
	var i int
	fmt.Println("Please enter an integer:")
	fmt.Scan(&i)
	fmt.Println("Integer entered: ", i)

	//  Read string
	var str string
	fmt.Println("\nPlease enter a word:")
	fmt.Scan(&str)
	fmt.Println("Word entered: ", str)

}
