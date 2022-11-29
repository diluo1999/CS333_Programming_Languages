CS333 - Project 1 - README
Di Luo
02/19/2020

Directory Layout:
.
└── Project01
    ├── README.txt
    ├── task1.c
    ├── task2.c
    ├── task3.c
    ├── task4.c
    └── task5.c

Run and build configuration for C:
macOS Mojave Version 10.14.6 - Apple clang version 11.0.0 (clang-1100.0.33.16)

Description for each subsection:
C:
  Task 1
    Compile:
            gcc -o task1 task1.c
    Run:
            ./task1
    Output:
            The number of bytes that each basic type uses and information 
            stored by each byte in memory are printed. char takes 1 byte. 
            short takes 2 bytes. int takes 4 bytes. long takes 8 bytes. 
            float takes 4 bytes. double takes 8 bytes.
    Questions:
        a. Is the machine you are using a big-endian or little-endian machine?
            little-endian
        b. How does this program tell you?
            When printing the int 0x01234567, the result is
            0: 67
            1: 45
            2: 23
            3: 01
            The output starts with the least-significant byte so the machine
            is little-endian.

  Task 2
    Compile:
            gcc -o task2 task2.c
    Run:
            ./task2
    Output:
            Many lines showing the index of the byte in memory and its 
            content. After 1 thousand and a few hundred of lines the 
            execution stopped and print "Segmentation fault:11".
    Questions:
        a. What happens at the end of the process?
            The loop terminated after printing 1768 times and showd 
            "Segmentation fault: 11". This is because we didn't 
            allocate memory after using.
            If without a newline, the final result is the same but 
            the loop terminated with less iterations
        b. Can you find the other variables?
            No, I couldn't find other variables like 0x01234567 or 0x76543210
  
  Task 3
    Compile:
            gcc -o task3 task3.c
    Run:
            ./task3
    Output:
            N/A
    Observation:
            Without free(), the memory used kept increasing. After increasing
            for around 300 MB, the execution terminated and the memory dropped
            directly to the amount before the execution.
            With free(), the memory used stayed the same until the execution
            terminated by itself. 

  Task 4
    Compile:
            gcc -o task4 task4.c
    Run:
            ./task4
    Output:
            12 lines were printed with index 0-11 and some lines contain the 
            data of the variables in the struct.
    Questions:
        a. Does the sizeof result match your expectation?
            No. I defined the struct to contain 9 types, which is odd, but 
            the result gave 12, which is greater than mine and it's even.
        b. Are there any gaps in the way the fields of the structure are laid out?
            Yes. Between different basic types there are gaps, which are 
            varying since in my terminal one gap is 1-line and the other
            is 2-line, and there is no gap between data with the same basic type.

  Task 5
    Compile:
            gcc -o task5 task5.c
    Run:
            ./task5
    Output:
            Nothing.
    Observation:
            When passing in a string that is very long (75 characters) and 
            trying to put it into a small-size array, the decision variable 
            within the function was overwritten so that the program crashed 
            instead of printing safe or hacked. This is because the string 
            is too long that the array cannot cover it. 
            Then I tried to make a struct with a fixed size string and an 
            int inside the struct. Then overwrite the end of the string 
            and see if it affects the value of the int. The program still 
            crashed.

Comment from Ying: The reason why you got "Abort trap: 6" in your task 5 is that your C compiler is so smart that the strcpy function can handle the overflow. But, there are compilers that cannot let the strcpy catch the overflow. So, the if statement coupled with the decision is to check the possible overflow. 


  Extension:
    I took three extension for this project. The first one is to do some research 
    regarding a fifth language, for which I chose Swift, and have a paragraph of 
    description for it.

    The second one is to make the safe/hacked C program use a string from the command line.
    I include my code in task5.c. When there is no string from command line, the terminal
    printed (null) Segmentation fault:11; when there is string from command line, the terminal
    printed the input string and Abort trap: 6.

    The thrid extension is to find the floating point number in C to which adding one would 
    return the same number. The extension is stored in the file extension1.c.
    Compile:
            gcc -o extension1 extension1.c
    Run:
            ./extension1
    Output:
            The value of floating number a is 999999995904.000000.
            The value of a + 1.0 is 999999995904.000000.
    The result shows that the floating point number 1e+12 or 999999995904.000000 to which 
    adding one would return the same number.
 