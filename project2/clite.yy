/**
 * CS333 Project 2
 * clite.yy
 * Parser for Clite
 *
 * Di Luo
 * 02/25/2020 
 */        

D   [0-9]

%%
{D}\.{D}*|[1-9]{D}+\.{D}*       {printf("Float-%s\n", yytext);}
{D}|[1-9]{D}+                   {printf("Integer-%s\n", yytext);}
if|else|while|for|int|float     {printf("Keyword-%s\n", yytext);}
[a-zA-Z]+\d*                    {printf("Identifier-%s\n", yytext);}
"=="|"<"|">"|"<="|">="          {printf("Comparison-%s\n", yytext);}
"="                             {printf("Assignment\n");}
"+"|"-"|"*"|"/"                 {printf("Operator-%s\n", yytext);}
"{"                             {printf("Open-bracket\n");}
"}"                             {printf("Close-bracket\n");}
"("                             {printf("Open-paren\n");}
")"                             {printf("Close-paren\n");}
[ \t\n]+
";"


%%

int main ( int argc, char *argv[] ) {
    
    if (argc > 1)
        yyin = fopen( argv[1], "r" );

    yylex();
    
    return 0;

}