

%{
#include "y.tab.h"
%}
%%
hello {return HELLO;}
.     { }
\n    { }
%%
int yywrap(){
return 1;
}