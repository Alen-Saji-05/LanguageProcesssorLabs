#include<stdio.h>
#include<string.h>
#include<ctype.h>
int tvc=1;
int checkop(char sy)
{
	return(sy=='+'||sy=='*'||sy=='/'||sy=='-');
}
int gp(char opsy)
{
	if(opsy=='*'||opsy=='/') return 2;
        if(opsy=='+'||opsy=='-') return 1;
        return 0;
}
int main()
{
	char exp[100];
	char opstack[100][10];
	char orstack[100];
	int  optop=-1;
	int  ortop=-1;
	printf("Enter Expression");
	scanf("%s",exp);
	printf("Three Adresss Code : \n");
   	for(int i=2;i<strlen(exp);i++)
   	{
   		if(isalnum(exp[i]))
        	{
			opstack[++optop][0]=exp[i];
			opstack[optop][1]='\0';
		}
		else if(checkop(exp[i]))
		{
			if(gp(exp[i])<=gp(orstack[ortop]))
			{
				char cuor=orstack[ortop--];
				char op1[20],op2[20];
				strcpy(op2,opstack[optop--]);
				strcpy(op1,opstack[optop--]);
				char tempvar[10];
				sprintf(tempvar,"t%d",tvc);
				printf("%s=%s%c%s\n",tempvar,op1,cuor,op2);
				strcpy(opstack[++optop],tempvar);
				tvc++;
			}
			orstack[++ortop]=exp[i];
        }
    }
	while(ortop>=0)
	{
				char cuor=orstack[ortop--];
				char op1[20],op2[20];
				strcpy(op2,opstack[optop--]);
				strcpy(op1,opstack[optop--]);
				char tempvar[10];
				sprintf(tempvar,"t%d",tvc);
				printf("%s=%s%c%s\n",tempvar,op1,cuor,op2);
				strcpy(opstack[++optop],tempvar);
				tvc++;
	}
	printf("%c=%s\n",exp[0],opstack[optop]);
	return 0;
}
        
   