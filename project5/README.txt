CS333 - Project 5 - README
Di Luo
04/25/2020

Directory Layout:
└── Project05
    ├── README.txt
    ├── clltest.c
    ├── linkedlist.h
    ├── llist.c
    ├── llist.js
    ├── lllist.go
    ├── lltest.go
    ├── lltest.js
    └── lltest_str.go


Run and build configuration for C:
macOS Catalina Version 10.15.6 - Apple clang version 11.0.3 (clang-1103.0.32.59)

Description for each subsection:
C:
  Task 1
    This is the C programming task 1. The task is to create a generic linked 
    list class in C. LinkedList struct has a head pointer and a Node struct. 
    Functions enable the linked list to push, pop, append, etc. Then the functions 
    are tested with test file clltest.c. The test has two portions and each 
    portion exams with a different data type. At the end of the Float portion, 
    there are testing codes for extensions.

    Compile:
        gcc -o clltest clltest.c llist.c
    Run:
        ./clltest
    Output:
        Part 1: Integer
        After initialization
        value: 18
        value: 16
        value: 14
        value: 12
        value: 10
        value: 8
        value: 6
        value: 4
        value: 2
        value: 0

        After squaring
        value: 324
        value: 256
        value: 196
        value: 144
        value: 100
        value: 64
        value: 36
        value: 16
        value: 4
        value: 0

        removed: 16

        No instance of 11

        After removals
        value: 324
        value: 256
        value: 196
        value: 144
        value: 100
        value: 64
        value: 36
        value: 4
        value: 0

        After append
        value: 324
        value: 256
        value: 196
        value: 144
        value: 100
        value: 64
        value: 36
        value: 4
        value: 0
        value: 11

        After clear

        After appending
        value: 0
        value: 1
        value: 2
        value: 3
        value: 4

        popped: 0
        popped: 1

        After popping
        value: 2
        value: 3
        value: 4

        List size: 3


        Part 2: Float
        After initialization
        value: 18.500000
        value: 16.500000
        value: 14.500000
        value: 12.500000
        value: 10.500000
        value: 8.500000
        value: 6.500000
        value: 4.500000
        value: 2.500000
        value: 0.500000

        After squaring
        value: 342.250000
        value: 272.250000
        value: 210.250000
        value: 156.250000
        value: 110.250000
        value: 72.250000
        value: 42.250000
        value: 20.250000
        value: 6.250000
        value: 0.250000

        removed: 20.250000

        No instance of 11.500000

        After removals
        value: 342.250000
        value: 272.250000
        value: 210.250000
        value: 156.250000
        value: 110.250000
        value: 72.250000
        value: 42.250000
        value: 6.250000
        value: 0.250000

        After append
        value: 342.250000
        value: 272.250000
        value: 210.250000
        value: 156.250000
        value: 110.250000
        value: 72.250000
        value: 42.250000
        value: 6.250000
        value: 0.250000
        value: 11.500000

        After clear

        After appending
        value: 0.500000
        value: 1.500000
        value: 2.500000
        value: 3.500000
        value: 4.500000

        popped: 0.500000
        popped: 1.500000

        After popping
        value: 2.500000
        value: 3.500000
        value: 4.500000

        List size: 3

        Restore the list to the state before append and pop
        value: 0.500000
        value: 1.500000
        value: 2.500000
        value: 3.500000
        value: 4.500000

        deleted: 2.500000

        After deleting
        value: 0.500000
        value: 1.500000
        value: 3.500000
        value: 4.500000

        Check if the list is empty

        List is not empty

        Check the index of 4.50000

        4.5 is in the list with index 3
    
  Extension:
    I took two extensions for this project. 
    
    The first extension is to create other helper functions for generic 
    LinkedList in C. I implemented ll_delete(), which deletes the node 
    indicated by the index and return the data; ll_isEmpty(), which checks 
    if the list is empty; ll_indexOf(), which find the index of the target 
    in the list if target is in the list and return -1 otherwise. The test 
    for them are at the end of the testing code and the results are shown 
    above.

    The second extension is to create ll_delete() function for generic 
    LinkedList in JavaScript. The description of this extension is in the 
    section below and in the Wiki page.


JavaScript:
  This is the selected language programming task in JavaScript. 

  Task 1
    This is the JavaScript programming task 1, implements linked list 
    and tests its functionalities. The testing functions in lltest.js 
    create lists in different data types and test each methods. The 
    extension of creating ll_delete() and its testing function are also 
    included.

    Run:
        node lltest.js
    Output:
        Part 1: Integer

        After initialization

        18
        16
        14
        12
        10
        8
        6
        4
        2
        0

        After squaring

        324
        256
        196
        144
        100
        64
        36
        16
        4
        0

        removed: 16

        No instance of 11

        After removals

        324
        256
        196
        144
        100
        64
        36
        4
        0

        After append

        324
        256
        196
        144
        100
        64
        36
        4
        0
        11

        After clear


        After appending

        0
        1
        2
        3
        4

        popped: 0
        popped: 1

        After popping

        2
        3
        4

        List size: 3

        Reset the list to the rebuilded version.

        0
        1
        2
        3
        4

        deleted: 2

        After deleting node with index 2

        0
        1
        3
        4


        Part 2: String

        After initialization

        e
        d
        c
        b
        a

        removed: c

        No instance of f

        After removals

        e
        d
        b
        a

        After append

        e
        d
        b
        a
        f

        After clear


        After appending

        one
        two
        three
        four

        popped: one
        popped: two

        After popping

        three
        four

        List size: 2

        Reset the list to the rebuilded version.

        one
        two
        three
        four

        deleted: three

        After deleting node with index 2

        one
        two
        four

Go:
  This is the selected language programming task in Go. 

  (1) Test int linkedlist:

    Run: 
      go run lllist.go lltest.go

    lllist.go implements a generic doubly linked list in Go.
    lltest.go contains test code for an int linked list.

  (2) Test string linkedlist:

    Run: 
      go run lllist.go lltest_str.go

    lltest_str.go contains test code for a string linked list.
