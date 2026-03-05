%{
    #include<stdio.h>
%}
DIGIT [0-9]
%%
{DIGIT}+ {printf("Integer :%s\n",yytext);}
{DIGIT}+"."{DIGIT}+ {printf("Float :%s\n",yytext);}
[+\-*/%] {printf("Operator : %s\n",yytext);}
[\t] ;
. ;
%%
int yywrap(){ return 1; }
int main()
{
    yylex();
    return 0;
}