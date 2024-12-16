Que] Write a Flex program to check whether the entered 
string of parenthesis is balanced or not in each input 
text file.

%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>

int balance = 0;

%}

%%
"("     { balance++; }
")"     { balance--; }

[^()\n]+   ;  
\n      {
            if (balance == 0) {
                printf("Balanced\n");
            } else {
                printf("Not Balanced\n");
            }
            balance = 0; 
        }

%%

int main() {
    yylex();
    return 0;
}

