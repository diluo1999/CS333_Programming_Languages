            int count = 0;

DIGIT   [0-9]

%% 

{DIGIT}+    { printf("number: %10d\n", atoi(yytext));
            /*yytext a special flex string available to the C code
            It contains the text corresponding to the current token:
            the text matched by the regular expression */
            } 

\n  count++;

.   /* skip all other input */
 
%%

int main( int argc, char *argv[] ) {
    if (argc > 1)
        yyin = fopen( argv[1], "r" ); //where yylex reads its input
    yylex(); // a function of flex that read input till it is exhausted
    printf("There are %d lines in the file.\n", count);
    return 0;
}