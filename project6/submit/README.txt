CS333 - Project 5 - README
Di Luo
05/10/2020

Directory Layout:
.
├── C
│   ├── linkedlist.h
│   ├── llist.c
│   ├── task1.c
│   ├── task2_1.c
│   ├── task2_2.c
│   ├── task2_3.c
│   └── wctest.txt
├── Go
│   ├── task2.go
│   ├── task3.go
│   └── wc.go
├── JavaScript
│   ├── task1.js
│   ├── task2.js
│   ├── task3.js
│   └── wctest.txt
└── README.txt

3 directories, 15 files


Run and build configuration for C:
macOS Catalina Version 10.15.6 - Apple clang version 11.0.3 (clang-1103.0.32.59)

Description for each subsection:
C:
  Task 1
    This is the C programming task 1. The task is to create a word counter 
    that can count the number of occurrences of every word in a text file

    Compile:
        gcc -o task1 task1.c
    Run:
        ./task1 wctest.txt
    Output:
        the:17 
        of:7 
        and:6 
        was:5 
        in:4 
        with:4 
        a:3 
        windows:3 
        broken:2 
        wings:2 
        central:2 
        portion:2 
        had:2 
        been:2 
        but:2 
        up:2 
        were:2 
        these:1 
        blocked:1 
        wooden:1

  Task 2
    This is the C programming task 2. The task investigates signal handling 
    in C. Three files are created to create three programs that can respectively 
    can respond to a cntl-C (interrupt), handle a floating point exception, 
    and handle a segmentation fault error

   Task2_1: a program that can respond to a cntl-C (interrupt)
    The infinite loop continues until cntl-C is pressed. Then terminal prints
    the message

    Compile:
        gcc -o task2_1 task2_1.c
    Run:
        ./task2_1
    Output:
        cntl-C is pressed%

   Task2_2: a program that can handle a floating point exception
    When the program detects wrong floating point usage, such as 0 is being
    divided, then the program prints out the message.

    Compile:
        gcc -o task2_2 task2_2.c
    Run:
        ./task2_2
    Output:
        Inappropriate floating point usage

   Task2_3: a program that can handle a segmentation fault error
    When the program detects segmentation fault error, such as trying a access 
    NULL in memory, then the program prints out the message.

    Compile:
        gcc -o task2_3 task2_3.c
    Run:
        ./task2_3
    Output:
        Segmentation fault error

  Extension:
    I did extension on "Make your word counter more robust so that it is able 
    to handle invalid command-line inputs and invalid files." Testing code is 
    added to main funciton in task1.c that prints out appropriate message when 
    error appears, such as missing input file name and failing to open the file 
    (or the filename is wrong)

    Example
    Compile:
        gcc -o task1 task1.c
    Run:
        ./task1
    Output:
        Missing input. Filename is needed.%

    Run:
        ./task1 wctest.c
    Output:
        The file wctest.c cannot be opened
    

JavaScript:
  This is the selected language programming task in JavaScript. 

  Task 1
    This task implements a word counter.

    Run:
        node task1.js
    Output:
        the 17
        of 7
        and 6
        was 5
        with 4
        in 4
        a 3
        windows 3
        central 2
        portion 2
        wings 2
        were 2
        broken 2
        but 2
        up 2
        had 2
        been 2
        building 1
        grey 1
        lichen-blotched 1

  Task 2
    This task exams file I/O in JS, which includes open, close, read file 
    and binary finle; Reading from URLs; Interactive: input from user

    Run:
        node task2.js
    Output:
        What's your name?Di
        Hi Di! Welcome!

  Task 3
    This task investigates error handling in JS. Functions that tests try-
    catch blocks are included.

    Run:
        node task3.js
    Output:
        I am the exception message.
        No idea what kind of error it is. Maybe Syntax?


Go:
  This is the selected language programming tasks in Go. 

  Task 1: word counter

    Run: 
      go run wc.go

    wc.go implements a word counter in Go.

    Output:
        Sorted by frequency in descending order:
        the      17
        of      7
        and      6
        was      5
        with     4
        in      4
        windows     3
        a      3
        central     2
        wings     2
        stone     2
        up      2
        had      2
        broken     2
        been     2
        were     2
        portion     2
        but      2
        outsides 1
        roof  1

  Task 2:  

    Run: 
      go run task2.go

    task2.go shows how Go reads from and writes to a file.

  Task 3:  

    Run:
      go run task3.go

    task3.go shows how Go supports error handling.