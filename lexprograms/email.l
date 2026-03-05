%{
    #include<stdio.h>
%}
email [a-zA-z0-9._%+-]+@[a-zA-z]+\.[a-zA-z]{2,}
%%
{email} {printf("Email : %s\n",yytext);}
. ;
%%
int yywrap(void)
{
    return 1;
}
int main()
{
    yylex();
    return 0;
}