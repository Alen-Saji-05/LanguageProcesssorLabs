#include<stdio.h>
#include<string.h>
#include<ctype.h>
int is_key(char *word)
{
    char keywords[][10]={"int","float","char","if","else","while","for","do","return"};
    for(int i=0;i<8;i++)
    {
        if(strcmp(word,keywords[i])==0) return 1;
    }
    return 0;
}
int main()
{
    FILE *f;
    f=fopen("input.txt","r");
    if(!f) {printf("File Not Found\n");return 0;}
    char buffer[100];
    int bin=0;
    int state=0;
    int ch;
    char sym_tabel[100][100];
    int sym_index=0;
    while((ch=fgetc(f))!=EOF)
    {
        switch(state)
        {
            case 0: 
            {if (isspace(ch)) break;
            if(ch=='<') state=1;
            else if(ch=='>') state=4;
            else if(ch=='!') state=7;
            else if(ch=='=') state=10;
            else if(ch=='+') state=13;
            else if(ch=='-') state=14;
            else if(ch=='*') state=15;
            else if(ch=='/') state=16;
            else if(ch=='&') state=17;
            else if(ch=='|') state=19;
            else if(isdigit(ch)) 
            {
                bin=0;
                buffer[bin++]=ch;
                state=21;
            }
            else if(isalpha(ch)||ch=='_'){
                bin=0;
                buffer[bin++]=ch;
                state=22;
            }
            else{
                printf("%c - <Special Character>\n",ch);
            }
            break;
            }
            case 1:
            {
                if(ch=='=') state=2;
                else
                {
                    ungetc(ch,f);
                    state=3;
                }
                break;
            }
            case 2:
            {
                printf("<= - <RELOP,LE>\n");
                ungetc(ch,f);
                state=0;
                break;
            }
            case 3:
            {
                printf("< - <RELOP,LT>\n");
                ungetc(ch,f);
                state=0;
                break;
            }
            case 4:
            {
                if(ch=='=') state=5;
                else
                {
                    ungetc(ch,f);
                    state=6;
                }
                break;
            }
            case 5:
            {
                printf(">= - <RELOP,GE>\n");
                ungetc(ch,f);
                state=0;
                break;
            }
            case 6:
            {
                printf("> - <RELOP,GT>\n");
                ungetc(ch,f);
                state=0;
                break;
            }
            case 7:
            {
                if(ch=='=') state=8;
                else
                {
                    ungetc(ch,f);
                    state=9;
                }
                break;
            }
            case 8:
            {
                printf("!= - <RELOP,NE>\n");
                ungetc(ch,f);
                state=0;
                break;
            }
            case 9:
            {
                printf("! - <LOGOP,NOT>\n");
                ungetc(ch,f);
                state=0;
                break;
            }
            case 10:
            {
                if(ch=='=') state=11;
                else
                {
                    ungetc(ch,f);
                    state=12;
                }
                break;               
            }
            case 11:
            {
                printf("== - <RELOP,EQ>\n");
                ungetc(ch,f);
                state=0;
                break;
            }
            case 12:
            {
                printf("= - <ASSOP>\n");
                ungetc(ch,f);
                state=0;
                break;
            }
            case 13:
            {
                printf("+ - <ARTOP>\n");
                ungetc(ch,f);
                state=0;
                break;
            }
            case 14:
            {
                printf("- - <ARTOP>\n");
                ungetc(ch,f);
                state=0;
                break;
            }
            case 15:
            {
                printf("* - <ARTOP>\n");
                ungetc(ch,f);
                state=0;
                break;
            }
            case 16:
            {
                printf("/ - <ARTOP>\n");
                ungetc(ch,f);
                state=0;
                break;
            }
            case 17:
            {
                if(ch=='&') state=18;
                else
                {
                    printf("& - <Special Character>\n");
                    ungetc(ch,f);
                }
                break;
            }
            case 18:
            {
                printf("&& - <LOGOP>\n");
                ungetc(ch,f);
                state=0;
                break;
            }
            case 19:
            {
                if(ch=='|') state=20;
                else
                {
                    printf("| - <Special Character>\n");
                    ungetc(ch,f);
                }
                break;
            }
            case 20:
            {
                printf("|| - <LOGOP>\n");
                ungetc(ch,f);
                state=0;
                break;
            }
            case 21:
            {
                if(isdigit(ch))
                {
                    buffer[bin++]=ch;
                }
                else
                {
                    buffer[bin]='\0';
                    printf("%s - <CONSTANT>\n",buffer);
                    state=0;
                    ungetc(ch,f);
                }
                break;
            }
            case 22:
            {
                if(isalnum(ch)||ch=='_')
                {
                    buffer[bin++]=ch;
                }
                else
                {
                    buffer[bin]='\0';
                    if(is_key(buffer))
                    {
                        printf("%s - <KEYWORD>\n",buffer);
                    }
                    else
                    {
                        int found=-1;
                        for(int i=0;i<sym_index;i++)
                        {
                            if(strcmp(sym_tabel[i],buffer)==0)
                            {
                                found=i;
                            }
                        }
                        if(found!=-1)
                        {
                            printf("%s - <IDENTIFER #%d>\n",buffer,found);
                        }
                        else
                        {
                            strcpy(sym_tabel[sym_index],buffer);
                            printf("%s - <IDENTIFER #%d>\n",buffer,sym_index);
                            sym_index++;
                        }
                        
                    }
                    ungetc(ch,f);
                    state=0;
                }
                break;
            }
        }
    }
    printf("\n\n");
    printf("SYMBOL TABLE\n");
    printf("IDENTIFIER\tLOACTION\n");
    for(int i=0;i<sym_index;i++)
    {
        printf("%s\t%d\n",sym_tabel[i],i);
    }
    fclose(f);
    return 0;
}
