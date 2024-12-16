To Study YACC. Write a YACC Program to display 
message “Have  a good Day”. 


%{
#include<stdio.h>
#include "y.tab.h"
%}

%token HELLO

%%
begin:
     |msg
     ;
msg: HELLO {printf("Have a good day");}
   
%%

int main()
{
   yyparse();
   return 0;
}
void yyerror(const char *s)
{
   printf("Error: %s\n", s);
}
