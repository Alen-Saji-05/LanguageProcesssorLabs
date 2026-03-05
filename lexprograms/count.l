%{
    #include<stdio.h>
    int vowels=0,cons=0,digits=0,special=0;
%}
%%
[aeiouAEIOU] {vowels++;}
[0-9] {digits++;}
[a-zA-z] {cons++;}
. {special++;}
%%
int yywrap(void)
{
    return 1;
}
int main()
{
    yylex();
    printf("Vowels :%d\n",vowels);
    printf("cons :%d\n",cons);
    printf("digit :%d\n",digits);
    printf("special :%d\n",special);
    return 0;
}