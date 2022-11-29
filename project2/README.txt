CS333 - Project 2 - README
Di Luo
03/01/2020

Directory Layout:
.
├── C
│   ├── clite.yy
│   ├── clite2.yy
│   ├── count.yy
│   ├── encode.txt
│   ├── encode.yy
│   ├── html.yy
│   ├── htmltest.txt
│   ├── p2-example.c
│   ├── p2-example2.c
│   ├── p2-example3.c
│   ├── p2.txt
│   └── test_count.txt
├── Go
│   └── hello.go
├── JavaScript
│   └── helloWorld.js
├── README.txt
└── Swift
    └── HelloWorld
        └── HelloWorld
            ├── HelloWorld
            │   ├── AppDelegate.swift
            │   ├── Assets.xcassets
            │   │   ├── AppIcon.appiconset
            │   │   │   └── Contents.json
            │   │   └── Contents.json
            │   ├── Base.lproj
            │   │   ├── LaunchScreen.storyboard
            │   │   └── Main.storyboard
            │   ├── Info.plist
            │   ├── SceneDelegate.swift
            │   └── ViewController.swift
            └── HelloWorld.xcodeproj
                ├── project.pbxproj
                ├── project.xcworkspace
                │   ├── contents.xcworkspacedata
                │   ├── xcshareddata
                │   │   └── IDEWorkspaceChecks.plist
                │   └── xcuserdata
                │       └── Ronty.xcuserdatad
                │           └── UserInterfaceState.xcuserstate
                └── xcuserdata
                    └── Ronty.xcuserdatad
                        └── xcschemes
                            └── xcschememanagement.plist

Run and build configuration for C:
macOS Mojave Version 10.14.6 - Apple clang version 11.0.0 (clang-1100.0.33.16)

Description for each subsection:
C:
  Task 1
    This is the C programming task 1. encode.yy contains a program called encode that 
	takes any character in a-z or A-Z and shifts it 13 spaces forward in the alphabet,
	with wraparound from z back to a. encode.txt tests the encode program by showing
	that running the output of encode through encode again will give the original 
	document. 

    Compile:
	flex encode.yy
	gcc -o encode lex.yy.c -ll
    Run:
	./encode encode.txt
    Output:
	Line 1-4 (a, b, A, B) are encoded as the original line 5-8 (n, o, N, O) and line 
	5-8 (n, o, N, O) are encoded as the original line 1-4 (a, b, A, B).
    
  Task 2
    This is the C programming task 2. count.yy contains a program called count that reads
	in a text file and tells you not only the number of rows and characters, but also
	how many of each vowel [a, e, i, o, u] are in the file. test_count.txt tests the
	program with the string "Hello/nWorld".

    Compile:
	flex count.yy
	gcc -o count lex.yy.c -ll
    Run:
	./count test_count.txt
    Output:
	# of rows = 2
	# of chars = 12
	# of a = 0
	# of e = 1
	# of i = 0
	# of o = 2
	# of u = 0
  
  Task 3
    This is the C programming task 3. html.yy contains a program strips an html file of	
	all tags and comments. It also strips the file of all whitespace except for a 
	blank line wherever there used to be a <p> tag. htmltest.txt contains the example
	for testing. p2.txt contains the web page to be examined.

    Compile:
	flex html.yy
	gcc -o html lex.yy.c -ll
    Run with htmltest.txt:
	./html htmltest.txt
    Output:
	ThisisapagetitleHereisaheader

	Hereissomebodytextinaparagraph

	Hereisalinktocs.colby.eduinsideaparagraph.

	which is identical to the sample result.

    Run with p2.txt:
	./html p2.txt
    Output:
	Project2|CS333CS333TopicsNotesHomeworkHomework1Homework2Homework3Homework4Homew
	ork5Homework6Homework7Homework8Homework9ProjectsProject1Project2Project3Project4
	Project5Project6Project7Project8Project9ReferenceMaterialsCS333ProgrammingLangua
	gesProject2$(function(){$("#index").addClass("active")})LexicalAnalysis

	Thefirstthingwehavetodowithanyprogramminglanguageisbuildalexicalanalyzerthatconver
	tsatextstringintoaseriesoftokens.Therearelotsoftoolsforhandlingthis.Forthisassig
	nment,you'llmakeuseoftheFlexlexicalanalysistoolandbuildafewdifferentparsers.Tasks
	...
	The output is the content of the Project 2 page. 

  Task 4
    This is the C programming task 4. clite.yy contains a parser for Clite that interprets
	a program into a sequence of strings, one per line. p2-example.c contains the 
	sample program that will be tested with.
    Compile:
	flex clite.yy
	gcc -o clite lex.yy.c -ll
    Run:
	./clite p2-example.c
    Output:
	Keyword-int
	Identifier-main
	Open-paren
	Close-paren
	Open-bracket
	Keyword-int
	...
	Which is almost identical to the sample result.

  Extension
    I took two extensions for this project. First one is to get comments working properly 
	in the parser for Clite and to try out a variety of examples. clite2.yy contains 
	the new version of parser for Clite with the support for comment. p2-example2.c 
	contains the sample program that will be tested with.
    Compile:
	flex clite2.yy
	gcc -o clite2 lex.yy.c -ll

    Run:
	./clite2 p2-example2.c
    Output:
	Keyword-int
	Identifier-main
	Open-paren
	Close-paren
	Open-bracket
	Comment-/*The main function compares two numbers.*/
	Keyword-int
	...
	Which proves the correctness of the new parser.

    Another test file is created in p2-example3.c that has a comment across lines.

    Run:
	./clite2 p2-example3.c
    Output:
	Keyword-int
	Identifier-main
	Open-paren
	Close-paren
	Open-bracket
	Comment-/*The main function compares two numbers: 
    		a equaling 6 and b equaling 5.0.*/
	Keyword-int
	...
	Which also proves the correctness of the new parser.


    Second extension is to do a third language, which is covered in the Swift section below.

JavaScript:
    This is the selected language programming task in JavaScript. helloWorld.js contains a
	hello world program in JavaScript that plays with variable declaration in 
	JavaScript. The program creates a 2 var with no initial value and 1 var with 
	initial value, and loop through them to see which one has value. 

    Run (with Node.js installed): 
	node helloWorld.js
    Output:
	var a is undefined.

	var b is undefined.

	var c is defined with value Hello World!.

Go:
    This is the selected language programming task in Go.
  
    Run:
	go run hello.go

    hello.go showcases how go programs print text, do math and boolean operations, 
    and prompts for user input from the keyboard.

    Output:
      	Hello, world!
      	I love Go!
      	1 + 2 = 3
      	9 - 20 = -11
      	7 * 9 = 63
      	6 / 3 = 2
      	true AND false is:  false
      	true OR false is:  true
      	NOT true is:  false

      	Please enter your name.
      	Yixuan
      	Hi, Yixuan! I'm Go!

Extension
Swift:
    This is the extension of language programming task in Swift. HelloWorld.xcodeproj 
	contains a hello world app that displays Hello World on the screen of a simulated 
	iPhone, and by pressing the displayed words, Hello World! will also be printed in
	the console output. 

    Run: 
	Open HelloWorld.xcodeproj with Xcode and simulate the app.
    Output:
	A app in a simulated iPhone that displays Hello World! and print Hello World when
	the button is pressed.

