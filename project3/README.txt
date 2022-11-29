CS333 - Project 3 - README
Di Luo
03/04/2020

Directory Layout:
.
├── C
│   ├── cstk.c
│   ├── cstk.h
│   ├── cstktest.c
│   └── cstktest2.c
├── Go
│   ├── task1.go
│   ├── task2.go
│   └── task3.go
├── JavaScript
│   ├── extension2.js
│   ├── task1.js
│   ├── task2.js
│   └── task3.js
└── README.txt


Run and build configuration for C:
macOS Mojave Version 10.14.6 - Apple clang version 11.0.0 (clang-1100.0.33.16)

Description for each subsection:
C:
  Task 1
    This is the C programming task 1. cstk.h is created, which includes the declaration of
	the global variable CSTK_MAX, the struct stack, and functions for manipulating the
	stack.
    
  Task 2
    This is the C programming task 2. cstk.c is created including the implementation of 
	the stack functions. 
  
  Task 3
    This is the C programming task 3. The stack I implemented is tested with cstktest.c.

    Compile:
	gcc -o cstktest cstktest.c cstk.c
    Run:
	./cstktest
    Output:
	The original list: 0 1 2 3 4 5 6 7 8 9 
	The reversed list: 9 8 7 6 5 4 3 2 1 0 

  Extension 1
    First one is to make the stack more robust so that it can handle the overflow errors.
	Some other functions for handling and checking the status of the stack are also 
	added to cstk.c. The function stk_peek returns the top element of the stack; 
	stk_isempty checks if the stack is empty; stk_isfull checks if the stack is full;
	stk_size checks and returns the number of current occupied spots in the stack. In
	addition, the checks in stk_push and stk_pop are added to print out message when 
	stack is full/empty so that push/pop won't work normally. The new test file 
	cstktest2.c tests these new functions by calling them before and after adding 
	elements into the stack.

    Compile:
	gcc -o cstktest2 cstktest2.c cstk.c
    Run:
	./cstktest2
    Output:
	The list: Could not peek, Stack is empty.
	The top element of the stack is -2147483648.
	The stack is empty.
	The stack is not full.
	Currently 0 spots in stack are occupied.
	The list: 0 1 2 3 4 5 6 7 8 9 The top element of the stack is 9.
	The stack is not empty.
	The stack is not full.
	Currently 10 spots in stack are occupied.


    Other extensions are in Part II.


JavaScript:
    This is the selected language programming task in JavaScript. 

  Task 1
    This is the JavaScript programming task 1, which demonstrates the rules for identifier
 	naming, variable declarations and identifier scoping. The program checks the 
	case-sensitive identity of JavaScript, and tests the scope in JavaScript.

    Run:
	node task1.js
    Output:
	Content in Student:A
	Content in student:B
	name in global scope: Di
	name in function scope: iD
	check name value, should be unmodified: Di

  Task 2
    This is the JavaScript programming task 2, which executes a binary search on a list or
	array of numbers. The test code creates an array and searched for 2 values, one is 
	in the array and the other doesn't.

    Run:
	node task2.js
    Output:
	The array is [1,3,5,7,9]
	Check if 5 can be found.
	5 is found.
	Check if 2 can be found.
	2 is NOT found.

  Task 3
    This is the JavaScript programming task 3, which demonstrates all of the basic built-in 
	types and how to construct aggregate types. Variables of different types are created.
	class and struct are created. Standard operations are tested between each type.

    Run:
	node task3.js
    Output:
	See Wiki page.

  Extension 2
    This is the JavaScript programming extension 2, which demonstrates whether functions are 
	a basic data type and whether a variable can hold an arbitrary function.

    Run:
	node extension2.js
    Output:
	1
	The function greeting is for printing out "Hello!".
	The type of the function greeting is  object

  Extension 3
    This is the JavaScript programming extension 2, which include other example programs 
	that show unique features of the syntax, naming, or scoping & Develop explicit 
	comparison code in Python, Java, or C and compare and contrast it with JS.

    extension3.js:
    Run:
	node extension3.js
    Output:
	var: 
	0
	0
	let: 
	0
	1

    extension3.c
    Compile:
	gcc -o extension3 extension3.c
    Run:
	./extension3
    Output:
	i value in loop is 0
	i value in loop is 1
	i value in loop is 2
	i value out of loop is 1
	

Go:
    These are the selected language programming tasks in Go. 

  Task 1:
  
    Run: 
      go run task1.go

    task1.go demonstrates the rules for identifier naming, variable declarations and 
	identifier scoping in Go.


  Task 2:
  
    Run: 
      go run task2.go

    task2.go executes a binary search on a list or array of numbers.


  Task 3:
  
    Run: 
      go run task3.go

    task3.go demonstrates all of the basic built-in types and how to construct aggregate
	types (e.g., array, structs), demonstrates which of the standard suite of 
	operators (+-/*%) manipulate which types and what the resulting type of each 
	operation is.

Extension
Swift:
    This is the extension of language programming task in Swift. 

