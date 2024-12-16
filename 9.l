Que] Write lex program to eliminate multiple spaces and tabs 
and replace 
with a single space and remove empty lines. 


%option noyywrap
%{
#include<stdio.h>
%}
%%
[ \t]+ {printf(" ");}
\n     { }
.      {printf("%s",yytext);}
%%
int main()
{
  yylex();
  return 0;

}


