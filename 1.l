Que] To Study Fast Lexical Analyzer Generator i.e. FLEX. 

%option noyywrap
%{
#include <stdio.h>
%}
%%
"hii"|"Hii"|"hi" { printf("Hello \n"); }
.+    { printf("Hii only.....!\n"); }
%%
int main()
{
    yylex();
    return 0;
}
