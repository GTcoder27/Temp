Que] Write a Flex program to recognize a valid arithmetic 
expression and to recognize the identifier and operators 
present and print them separately. 


%option noyywrap
%{
#include<stdio.h>
int v=0, op=0, id=0, flag=0;
%}
%%
[a-zA-Z][a-zA-Z0-9]* { id++; }      
[0-9]+ { id++; }                   
[+-/*=] { op++; }                    
"(" { v++; }
")" { v--; }                        
";" { flag = 1; }                   
.|\n { return 0; }                  
%%
int main()
{
    printf("Enter the expression: ");
    yylex();

    if(v == 0 && (op + 1) == id && flag == 0)
    {
        printf("Expression is Valid\n");
        printf("No of Operators: %d\n", op);
        printf("No of Identifiers: %d\n", id);
    }
    else
    {
        printf("Expression is Invalid\n");
    }

    return 0;
}
