#include<stdio.h>
#include<string.h>
char des[10],op1[10],op2[10],tac[20];
char op;
void main()
{
    printf("Enter The Three Address Code\n");
    scanf("%s",tac);
    if(sscanf(tac,"%[^=]=%s",des,op1)==2&&strchr(tac,'*')==NULL&&strchr(tac,'+')==NULL&&strchr(tac,'-')==NULL&&strchr(tac,'/')==NULL)
    {
        printf("Generated Code : \n");
        printf("MOVE %s,R1\n",op1);
        printf("MOVE R1,%s\n",des);
    }
    else if(sscanf(tac,"%[^=]=%[^+-*/]%c%s",des,op1,&op,op2)==4)
    {
        printf("Generated Code : \n");
        printf("MOVE %s,R1\n",op1);
        printf("MOVE %s,R2\n",op2);
        switch(op)
        {
            case '+':
            {
                printf("ADD R1,R2\n");
                break;
            }
            case '-':
            {
                printf("SUB R1,R2\n");
                break;
            }
            case '*':
            {
                printf("MUL R1,R2\n");
                break;
            }
            case '/':
            {
                printf("DIV R1,R2\n");
                break;
            }
        }
        printf("MOVE R1,%s\n",des);
    }
}