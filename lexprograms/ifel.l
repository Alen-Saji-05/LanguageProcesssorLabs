%{
    #include "y.tab.h"
%}
%%
"if" return IF;
"else" return ELSE;
[0-9]+ return NUM;
[a-zA-Z_][a-zA-Z0-9_]+ return ID;
"<="|">="|"=="|"!="|"<"|">" return relop;
"(" return '(';
")" return ')';
";" return ';';
'\n'  return '\n';
[\t]+ ;
. yytext[0];
%%
int yywrap(void)
{
    return 1;
}