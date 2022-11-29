CS333 - Project 7 - README
Di Luo
05/10/2020

Directory Layout:

Run and build configuration for C:
macOS Catalina Version 10.15.6 - Apple clang version 11.0.3 (clang-1103.0.32.59)

Description for each subsection:
C:
  Task 1
    This is the C programming task 1, in which we investigate on the average time per 
    call to allocate a certain amount of memory. We try the experiment with three 
    different memory size. The result shows that small size (10) and medium size 
    (100000000) are similar in speed, where as large size (1e11) takes much longer 
    than the other two. The reason for the difference can be that large size used by
    all resources in heap so that the computer needs to either enlarge the region or 
    store information in another place.

    Compile:
        gcc -o task1 task1.c my_timing.c
    Run:
        ./task1
    Output:
        Small Size Memory:Average Time: 0.000001
        Medium Size Memory:Average Time: 0.000001
        Large Size Memory:Average Time: 0.000367%
  
  Task 2
    This is the C programmimg task 2, in which we investigates on relation between 
    memory management call and the number of allocation and free operations the program 
    has executed. The program allocates/free a certain size of memory 1000 times and 
    we measures the first 100, the second 100 ... the tenth 100. The result shows that 
    for medium size and large size, each 100 times have most the same execution time. 
    But for small size, the first 100 times takes much longer than others, which is around 
    65 times longer than later cases. This might be interpreted that there are some initialization
    going around during the first time, such as finding the memory address.

    Compile:
        gcc -o task2 task2.c my_timing.c
    Run:
        ./task2
    Output:
        Small Size Memory:
        0
        Allocating 100 times takes: 0.000669
        Freeing 100 times takes: 0.000015
        1
        Allocating 100 times takes: 0.000008
        Freeing 100 times takes: 0.000007
        2
        Allocating 100 times takes: 0.000011
        Freeing 100 times takes: 0.000009
        3
        Allocating 100 times takes: 0.000012
        Freeing 100 times takes: 0.000006
        4
        Allocating 100 times takes: 0.000011
        Freeing 100 times takes: 0.000007
        5
        Allocating 100 times takes: 0.000010
        Freeing 100 times takes: 0.000010
        6
        Allocating 100 times takes: 0.000010
        Freeing 100 times takes: 0.000009
        7
        Allocating 100 times takes: 0.000008
        Freeing 100 times takes: 0.000009
        8
        Allocating 100 times takes: 0.000009
        Freeing 100 times takes: 0.000010
        9
        Allocating 100 times takes: 0.000008
        Freeing 100 times takes: 0.000009

        Medium Size Memory:
        0
        Allocating 100 times takes: 0.000013
        Freeing 100 times takes: 0.000064
        1
        Allocating 100 times takes: 0.000009
        Freeing 100 times takes: 0.000063
        2
        Allocating 100 times takes: 0.000008
        Freeing 100 times takes: 0.000064
        3
        Allocating 100 times takes: 0.000008
        Freeing 100 times takes: 0.000062
        4
        Allocating 100 times takes: 0.000009
        Freeing 100 times takes: 0.000062
        5
        Allocating 100 times takes: 0.000011
        Freeing 100 times takes: 0.000060
        6
        Allocating 100 times takes: 0.000010
        Freeing 100 times takes: 0.000062
        7
        Allocating 100 times takes: 0.000009
        Freeing 100 times takes: 0.000062
        8
        Allocating 100 times takes: 0.000010
        Freeing 100 times takes: 0.000062
        9
        Allocating 100 times takes: 0.000009
        Freeing 100 times takes: 0.000063

        Large Size Memory:
        0
        Allocating 100 times takes: 0.047159
        Freeing 100 times takes: 0.037121
        1
        Allocating 100 times takes: 0.048145
        Freeing 100 times takes: 0.037726
        2
        Allocating 100 times takes: 0.040866
        Freeing 100 times takes: 0.031547
        3
        Allocating 100 times takes: 0.041944
        Freeing 100 times takes: 0.032972
        4
        Allocating 100 times takes: 0.043518
        Freeing 100 times takes: 0.034118
        5
        Allocating 100 times takes: 0.053144
        Freeing 100 times takes: 0.039809
        6
        Allocating 100 times takes: 0.054669
        Freeing 100 times takes: 0.041062
        7
        Allocating 100 times takes: 0.050766
        Freeing 100 times takes: 0.039028
        8
        Allocating 100 times takes: 0.049196
        Freeing 100 times takes: 0.038223
        9
        Allocating 100 times takes: 0.043065
        Freeing 100 times takes: 0.034276


JavaScript:
  This is the selected language programming task in JavaScript. 

  Task 1
    This task researches on memory management algorithms in JavaScript.

    Run:
        node task1.js
    Output:
        David
        first
  
  Task 2
    This task researches in automatic memory management / garbage collection in JS

    Run:
        node task2.js
    Output:
        allocateAndFree spent time: 0ms
        allocateAndFree spent time: 0ms
        allocateAndFree spent time: 0ms
        allocateAndFree spent time: 0ms
        allocateAndFree spent time: 0ms
        allocateAndFree spent time: 0ms
        allocateAndFree spent time: 1ms
        allocateAndFree spent time: 0ms
        allocateAndFree spent time: 0ms
        allocateAndFree spent time: 0ms
        Garbage collection happens in the 7th function call.

Go:
  These are the selected language programming tasks in Go. 

  Task 1:

    Run: 
      go run task1.go
      

  Task 2:  

    Run: 
      go run task2.go
        