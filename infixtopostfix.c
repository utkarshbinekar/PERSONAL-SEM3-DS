#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define Max 10
char st[Max];
int top = -1;

char pop();
void push(char);
int prior(char);

void main()
{
    char infix[100];
    char postfix[100];
    printf("Enter the expression\n");
    gets(infix);
    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if (isalpha(infix[i]) != 0 || isdigit(infix[i]) != 0)
        {
            postfix[j] = infix[i];
            j++;
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (st[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }
            top--;
        }
        else
        {
            if (top == -1 || st[top] == '(')
            {
                push(infix[i]);
            }
            else
            {
                while (prior(st[top]) >= prior(infix[i]))
                {
                    postfix[j] = pop();
                    j++;
                    if (top == -1 || st[top] == '(')
                    {
                        break;
                    }
                }
                push(infix[i]);
            }
        }
        i++;
    }
    while (top >= -1)
    {
        postfix[j] = pop();
        j++;
    }
    puts(postfix);
}

void push(char p)
{
    if (top == Max - 1)
    {
        printf("Overflow");
    }
    else
    {
        top++;
        st[top] = p;
    }
}

char pop()
{
    char y = st[top];
    top--;
    return y;
}

int prior(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else
        return 2;
}