/**
 * CS333 Project 2
 * count.yy
 * Read in a text file and tells not only the number of rows and characters,
 * but also how many of each vowel a/A, e/E, i/I, o/O, u/U are in the file
 *
 * Di Luo
 * 02/25/2020 
 */        

    int num_rows = 0, num_chars = 0, num_a = 0, num_e = 0, num_i = 0, num_o = 0, num_u = 0;

%%
a|A   num_a++; num_chars++;
e|E   num_e++; num_chars++;
i|I   num_i++; num_chars++;
o|O   num_o++; num_chars++;
u|U   num_u++; num_chars++;
\n  num_rows++; num_chars++;
.   num_chars++;  

%%

int main ( int argc, char *argv[] ) {
    
    if (argc > 1)
        yyin = fopen( argv[1], "r" );

    yylex();
    
    printf("# of rows = %d\n# of chars = %d\n# of a = %d\n# of e = %d\n# of i = %d\n# of o = %d\n# of u = %d\n",
            num_rows, num_chars, num_a, num_e, num_i, num_o, num_u);

}