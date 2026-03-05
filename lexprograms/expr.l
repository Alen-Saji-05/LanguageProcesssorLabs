%{
    #include "y.tab.h"
%}
%%
[0-9]+ {yylval=atoi(yytext);return NUM;}
[+\-*/()] {return yytext[0];}
[\t] ;
. ;
%%
int yywrap(void)
{
    return 1;
}
