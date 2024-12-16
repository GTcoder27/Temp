Que] Write a Flex program to Count the number of IF 
conditions, printf and scanf statement in a program 
using the Lexical Analyzer


%option noyywrap
%{
#include <stdio.h>
int if_count = 0;
int printf_count = 0;
int scanf_count = 0;
%}

%%
"if"                { if_count++; }
"printf"            { printf_count++; }
"scanf"             { scanf_count++; }
[ \t\n]+            ;
.                   ;
%%

int main() {
    yylex();
    printf("Number of 'if' conditions: %d\n", if_count);
    printf("Number of 'printf' statements: %d\n", printf_count);
    printf("Number of 'scanf' statements: %d\n", scanf_count);

    return 0;
}