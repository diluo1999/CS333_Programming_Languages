CS333 - Project 8 - README
Di Luo
05/18/2020

Directory Layout:

Run and build configuration for C:
macOS Catalina Version 10.15.6 - Apple clang version 11.0.3 (clang-1103.0.32.59)

Description for each subsection:
C:
  Task 1
    This is the C programming task 1, in which we write a function that sorts an array.
    We used multi-threading and tested the improvement on speed with different number 
    of threads. According to the result, 2 threads is 1.2 times faster than 1 thread 
    and 4 threads is 4 times faster than 1 thread. The result for 2 threads doesn't 
    follows Amdahl's Law, but 4 thread does.

    Compile:
        gcc -o task1 task1.c my_timing.c
    Run:
        ./task1
    Output:
        1 thread: 0.003467 seconds
        2 threads: 0.002939 seconds
        4 threads: 0.000807 seconds

  Task 2
    This is the C programming task 2, in which we write a program that reads an 
    image and applies a pixel-wise operator to it with the help of multi-threading. 
    According to the result, 2 threads is around 2 times faster than 1 thread and 
    4 threads is around 4 times faster than 1 thread, which follows Amdahl's Law.

    Compile:
        gcc -o task2 task2.c my_timing.c ppmIO.c
    Run:
        ./task2 IMG_4203.ppm
    Output:
        1 thread
        Time: 0.012095 seconds
        2 threads
        Time: 0.007111 seconds
        4 threads
        Time: 0.003361 seconds


JavaScript:
  This is the selected language programming task in JavaScript. 

  Task 1
    This task researches on parallelism in JavaScript. The content is in Wiki.
        
Python:
  This is the selected language programming task in Python. (Only for Proj 8)

  Task 2_1
    This task implements a function in Python that sorts an array with 
    parallelism. 

    Run:
        python task2_1.py
    Output:
        Time of 1 thread in seconds: 0.10325800000000007.
        Time of 2 threads in seconds: 0.019113999999999964.
        Time of 4 threads in seconds: 0.006083000000000061.

  Task 2_2
    This task implements a program that reads an image and applies a 
    pixel-wise operator to it.

    Run:
        python task2_2.py miller.ppm
    Output:

Go:
  These are the selected language programming tasks in Go. 

  Task 1: Merge Sort

    Run: 
      go run task1.go

    Output:
        ---------------
        Sequential:
        First 10 elements in the unsorted array:
        [8081 7887 1847 4059 2081 1318 4425 2540 456 3300]
        First 10 elements in the sorted array:
        [2 2 5 5 6 7 7 8 9 10]

        It took 2.744245ms to sort an array sequentially

        ---------------
        Parallel:
        First 10 elements in the unsorted array:
        [4928 9781 3285 2826 2107 3490 8852 8011 3586 3481]
        First 10 elements in the sorted array:
        [1 2 2 2 3 4 5 8 8 10]

        It took 1.619054ms to sort an array parallelly
        ---------------

    The parallel implementation is 1.7 faster than the sequential implementation.


  Task 2: Image Processing  

    Run: 
      go run task2.go
