Que] Write Flex program to count and print the Number of 
pages lines, words, and characters in a given file. 

%option noyywrap
%{
#include<stdio.h>
int line_c =0, space_c=0,char_c=0,tt=0,word_c=0;
%}
%%
[\n] {line_c++;}
[ \t]+ {space_c++;}
[a-zA-Z]+ {word_c++ ; char_c++;}
. {char_c++;}
%%
int main()
{
    yylex();
    printf("Number of lines: %d\n",line_c);
    printf("Number of spaces: %d\n",space_c);
    printf("Number of characters: %d\n",char_c); 
    printf("Number of words: %d\n",word_c);
    return 0;
}