/*A program to convert infix expression to postfix expression*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

char s[50];
int top=-1;

/*a function to push elements into stack*/
void push(int x)
    {
        s[++top]=x;
    }

/* a function to pop from stack*/
char pop()
    {
        return s[top--];
    }

/*a function to compare the presedence of the operators*/
int p(char x)
    {
        if(x=='('||x=='#')
            return 1;
        else if(x=='+'||x=='-')
            return 2;
        else if(x=='*'||x=='/')
            return 3;
        else if(x=='$'||x=='^')
            return 4;
    }

/*main function*/
void main()
    {
        char infix[50], postfix[50];
        int i,j;
        printf("Enter the infix expression\n");
        gets(infix);
        push('#');

        for(i=0;i<strlen(infix);i++)
        {
            if(isalnum(infix[i]))
                postfix[j++]=infix[i];
            else if(infix[i]=='(')
                push(infix[i]);
            else if(infix[i]==')')
            {

                while(s[top]!='(')
                    postfix[j++]=pop();
                pop();/*this pop is to remove ( -open parenthesis */
                }
            else
            {
                while(p(s[top])>= p(infix[i]))
                    postfix[j++]=pop();
                push(infix[i]);
            }
            }/*end for */
            while(s[top]!='#')
                postfix[j++]=pop();
            postfix[j]='\0';
            printf("Infix exp is\n");
                puts(infix);
            printf("Corresponding postfix expression is \n");
                puts(postfix);
            getch();
            }
