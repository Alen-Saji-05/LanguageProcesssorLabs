    #include<stdio.h>
    #include<string.h>
    #include<ctype.h>
    #include<stdlib.h>
    #define MAX 100
    char input[MAX][50];
    char output[MAX][50];
    int isnum(char str[])
    {
        for(int i=0;str[i]!='\0';i++)
        {
            if(!isdigit(str[i])) return 0;
        }
        return 1;
    }
    int main()
    {
        int n,res;
        char lhs[10],op,or1[10],or2[10];
        printf("Enter Number of Expression : ");
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            printf("Enter Expression %d : ",i);
            scanf("%s",input[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(sscanf(input[i], "%[^=]=%[^+-*/]%c%[^+-*/]", lhs, or1, &op, or2) == 4)
            {
                if(isnum(or1)&&isnum(or2))
                {
                    int val1,val2;
                    val1=atoi(or1);
                    val2=atoi(or2);
                    switch(op)
                    {
                        case '+': res=val1+val2;break;
                        case '-': res=val1-val2;break;
                        case '*': res=val1*val2;break;
                        case '/': res=val1/val2;break;
                    }
                    sprintf(output[i],"%s=%d",lhs,res);
                }
                else strcpy(output[i],input[i]);
            }
            else strcpy(output[i],input[i]);
        }
        for(int i=0;i<n;i++)
        {
            printf("%s\n",output[i]);
        }
    }
                        