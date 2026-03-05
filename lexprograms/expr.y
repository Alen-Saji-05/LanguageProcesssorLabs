%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex(void);
    int yyerror(char *s);
%}
%token NUM
%left '+' '-'
%left '*' '/'
%%
S : E {printf("Valid Expression\n");}
;
E : E'+'E
| E'-'E
| E'*'E
| E'/'E
| NUM
;
%%
int main()
{
    yyparse();
    return 0;
}
int yyerror(char *s)
{
    printf("%s\n",s);
    return 0;
}