#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
char stack[100];
int top--;
void push(char x)
{
    stack[++top]=x;
}
char pop()
{
    if(top==-1)
        return -1;
    else    
        return stack[top--];
}
int priority(char x)
{
    if(x=='(')
        return 0;
    else if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='*')
        return 2;
    else 
        return -1;
}
int main()
{
    char exp[100];
    char *e,x;
    printf("\nEnter expression:");
    scanf("%s",&exp);
    printf("\n\n");
    while(e!='\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e=='(')
            push(*e);
        else if(*e==')')
        {
            while((x=pop()!='(')
                printf("%c",x);
        }
        else
        {
            while(priority(stack[top])>=priority(*e))
                printf("%c",pop());
            
        }
    }
}