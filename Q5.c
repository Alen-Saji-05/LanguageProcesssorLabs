#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void S();
void A();
void Sdash();
void Adash();
void B();
void error();
char input[100];
int i=0;
void match(char c)
{
	if(input[i]==c)
	{
		i++;
	}
	else error();
}
void error()
{
	printf("Rejected\n");
	exit(0);
}
void S()
{
	if(input[i]=='a')
	{
		match('a');
		Sdash();
	}
	else if(input[i]=='b')
	{
		match('b');
	}
	else error();
}
void Sdash()
{
	if(input[i]=='a')
	{
		A();
		match('d');
	}
	else if(input[i]=='c'||input[i]=='d')
	{
		B();
	}
	else error();
}
void A()
{
	if(input[i]=='a')
	{
		match('a');
		if(input[i]=='b')
		{
			Adash();
		}
		else if(input[i]=='c')
		{
			match('c');
		}
		else if(input[i]=='d')
		{
			return;
		}
	}
	else error();
}
void Adash()
{
	if(input[i]=='b') match('b');
}
void B()
{
	if(input[i]=='c')
	{
		match('c');
		match('c');
		match('d');
	}
	else if(input[i]=='d')
	{
		match('d');
		match('d');
		match('c');
	}
	else error();
}
void main()
{
    printf("Enter Expression : ");
    scanf("%s",input);
    S();
    if(input[i] == '\0')
        printf("String Accepted\n");
    else
        printf("Rejected\n");
}