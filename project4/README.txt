CS333 - Project 4 - README
Di Luo
03/11/2020

Directory Layout:
.
├── C
│   ├── quicksort.c
│   └── task2.c
├── Go
│   ├── task1.go
│   ├── task2.go
│   └── task3.go
├── JS
│   ├── task1.js
│   ├── task2.js
│   └── task3.js
└── README.txt


Run and build configuration for C:
macOS Mojave Version 10.14.6 - Apple clang version 11.0.0 (clang-1100.0.33.16)

Description for each subsection:
C:
  Task 1
    This is the C programming task 1. In quicksort.c, comparator function is implemented. 
	The main function uses qsort to sort an array with rules that the even numbers are 
	sorted in descending order and the odd numbers are sorted in ascending order.

    Compile:
	gcc -o quicksort quicksort.c
    Run:
	./quicksort
    Output:
	The sorted array is: 12 10 8 6 4 2 0 1 3 5 7 9 11 13

    Source: 
	1. https://www.geeksforgeeks.org/comparator-function-of-qsort-in-c/
	2. https://www.programmingsimplified.com/c/source-code/c-program-check-odd-even
  
  Task 2
    This is the C programming task 2. The program contains a function that takes in an 
	integer argument and returns its factorial value as an integer, and the main 
	function that takes in an integer argument from command-line and print out its 
	factorial value.

    Compile:
	gcc -o task2 task2.c
    Run:
	./task2
    Output:
	Factorial of 5 = 120
    Question:
	What does this demonstrate with respect to types and functions in C?
	
	The program shows that in C, function can be a data type that can be passed as 
	parameters and assigned to variables.

    Run (with command-line argument):
	./task2 12
	./task2 13
	./task2 14
	./task2 15
    Output:
	Factorial of 12 = 479001600
	Factorial of 13 = 1932053504
	Factorial of 14 = 1278945280
	Factorial of 15 = 2004310016
    Question:
	What is happening when you go from 12! to 13! to 14! to 15!?
	
	Calculating 12! returns the correct value but for 13, 14 and 15, the return values 
	are wrong. Even when goes from 13 to 14, the calculated factorial value decreases. 
	This is because the calculated value of factorial 13, 14 and 15 excess the maximum 
	value that the int type can represent.

    Source:
	1. https://www.programmingsimplified.com/c-program-find-factorial
	2. https://www.geeksforgeeks.org/find-largest-among-three-different-positive-
		numbers-using-command-line-argument/


JavaScript:
    This is the selected language programming task in JavaScript. 

  Task 1
    This is the JavaScript programming task 1, implements and tests control flow 
	statements in JS.

    Run:
	node task1.js
    Output:
	for loop and if/else test:
	esle is executed.
	for loop and if/else test:
	esle is executed.
	for loop and if/else test:
	esle is executed.
	while loop test:
	i value is3
	i value is4
	iPhone is a brand of smartphone.
	Sumsang is a brand of smartphone.
	Huawei is a brand of smartphone.
	switch statement test:
	iPhone: $799
	switch statement test:
	This smartphone brand cannot be recognized.

  Task 2
    This is the JavaScript programming task 2, which shows how functions are treated in JS

    Run:
	node task2.js
    Output:
	true
	func executes
	Testing func in func.
	func executes
	Function expression
	

  Task 3
    This is the JavaScript programming task 3, which implements a general sort algorithm 
	that can be used for any type and can be used to obtain any desired order

    Run:
	node task3.js
    Output:
	See Wiki page.

Go:
  These are the selected language programming tasks in Go. 

    Task 1:
  
    Run: 
      go run task1.go

    task1.go demonstrates control flow statements in Go.


    Task 2:
  
    Run: 
        go run task2.go

    task2.go shows how functions are treated in Go as a data type.


    Task 3:
  
    Run: 
        go run task3.go

    task3.go implements a generic quicksort algorithm.
  