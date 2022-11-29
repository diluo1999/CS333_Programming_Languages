/**
 * CS333 Project 2
 * html.yy
 * Strip an html file of all tags and comments
 *
 * Di Luo
 * 02/25/2020 
 */        

%%
\<p\>           {printf("\n\n");}
[ \t\n]+
(<[^<>]+>)

%%

int main ( int argc, char *argv[] ) {
    
    if (argc > 1)
        yyin = fopen( argv[1], "r" );

    yylex();
    
    return 0;

}