/**
 * Read in from a specified file,
 * replace aba in the file with ABA and replace ab+a with AB+A,
 * and print out the number of aba in the file.
 *
 * Note: swapping line 17 and 18 will give an incorrect result as
 * rules are executed in the order they defined in the file.
 *
 * flex -o test.yy.c test.yy
 * gcc -o test test.yy.c -ll
 */
      int count = 0;
%%
^aba$        { printf("ABA"); count++;}
^ab+a$       { printf("AB+A"); }
.            { printf("%s", yytext);}
%%
int main( int argc, char *argv[] ) {
    if (argc > 1)
        yyin = fopen( argv[1], "r" ); //where yylex reads its input
    yylex(); // a function of flex that read input till it is exhausted
    printf("\nThere are %d aba in the file.\n", count);
    return 0;
}