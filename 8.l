Que] Write lex program to extract all html tags in the given 
file.



%option noyywrap
%{
#include<stdio.h>
%}

%%
"<"[a-zA-Z]+[0-9]*">" { printf("HTML Tag found: %s\n", yytext); }
"<"[A-Za-z]+[0-9]*"/>" { printf("HTML Tag found: %s\n", yytext); }    
.|\n {}           
%%

int main() {
    yylex();
    return 0;
}


