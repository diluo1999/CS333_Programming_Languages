/**
 * Hello World: replace "blah" with "hello world" 
 * flex -o hello.yy.c hello.yy
 * gcc -o hello hello.yy.c -ll
 * echo "blah and another blah" | ./hello
 */

%%

blah    printf("hello world");

%%

int main ( int argc, char *argv[] ) {

  yylex();

  return 0;
  
}