%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex(void);
    int yyerror(const char *s);
%}
%token IF ELSE ID NUM relop
%nonassoc IFX
%nonassoc ELSE

%%
S : stmt'\n' {printf("Valid IF Statement\n");}
;
stmt : IF '(' cond ')' stmt %prec IFX
| IF '(' cond ')' stmt ELSE stmt
| ID ';'
;

cond : ID relop ID
| NUM relop  ID
| ID relop NUM
| NUM relop NUM
| ID 
| NUM 
;
%%
int main()
{
    printf("Enter if Statment : ");
    yyparse();
    return 0;
}
int yyerror(const char *s)
{
    printf("If-else Syntax Error\n");
    return 0;
}
