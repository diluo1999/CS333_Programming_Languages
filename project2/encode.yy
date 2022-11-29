/**
 * CS333 Project 2
 * encode.yy
 * takes any character in a-z or A-Z and shifts it 13 spaces 
 * forward in the alphabet, with wraparound from z back to a
 *
 * Di Luo
 * 02/25/2020 
 */        

%%
[a-z]   {int i = yytext[0];
         if (i<110)
            i = i + 13;
         else
            i = i - 13;
         printf("%c", i);}

[A-Z]   {int I = yytext[0];
         if (I<78)
            I = I + 13;
         else
            I = I - 13;
         printf("%c", I);} 

%%

int main ( int argc, char *argv[] ) {
    
    if (argc > 1)
        yyin = fopen( argv[1], "r" );

    yylex();
    
    return 0;

}