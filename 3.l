Que] 


%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

[0-9]+                      { printf("Entered word is a number.\n"); }
(if|else|while|printf|scanf) { printf("Keyword: %s\n", yytext); }
[a-zA-Z_]+[a-zA-Z0-9_]*      { printf("Identifier: %s\n", yytext); }
[@#$%^&*]                    { printf("Entered word is a symbol: %s\n", yytext); }
.                            { printf("Invalid character: %s\n", yytext); }

%%

int main() {
    printf("Enter the word or code to be checked: ");
    yylex();  // Start the lexical analysis
}
