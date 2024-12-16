Que] Write lex program to count all instance of she and he, 
including the instances of 
he that are included in she. 


%option noyywrap
%{
#include<stdio.h>
int he = 0 , she = 0, she_he = 0;
%}
%%
{
  "he"   {he++;}
  "she"  {she++,she_he++;}
  .      {}
}
%%
int main()
{
    yylex();
    printf("Number of 'he' words: %d\n", he);
    printf("Number of 'she' words: %d\n", she);
    printf("Number of 'he' in 'she' words: %d\n", (she_he+he));
    return 0;
}