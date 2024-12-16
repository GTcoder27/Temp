Que] Write a Flex program to check whether the entered word is VOWEL or NOT

%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
%}

%%
^[aeiouAEIOU].*  {printf("It's a vowel");}
^[^aieouAEIOU].* { printf("Not a Vowel\n");}
%%
int main()
    {
        printf("Entered the word to be checked:\n");
        yylex();
    }
