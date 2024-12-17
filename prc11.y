To Study YACC. Write a YACC Program to display 
message “Have  a good Day”. 


%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token HELLO

%%
begin:
     | msg
     ;
msg: HELLO { printf("Have a good day\n"); }
%%

void yyerror(const char *s) {
   
}

int main() {
   yyparse();
   return 0;
}
