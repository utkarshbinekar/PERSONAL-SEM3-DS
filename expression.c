#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define Max 10
char st[Max];
int top = -1;
int new_st[Max];
int topper = -1;
char pop();
void push(char);
int prior(char);
void infixtopostfix();
void new_push(int);
int new_pop();
void peek();
int postfixtoans();
char postfix[100];
void main()
{
    infixtopostfix();
    postfixtoans();
}
int postfixtoans()
{
    int i, val1, val2, ans;
    i = 0;
    while (postfix[i] != '\0')
    {
        if (isdigit(postfix[i]) != 0)
        {
            new_push(postfix[i] - 48);
        }
        else
        {
            val1 = new_pop();
            val2 = new_pop();
            switch (postfix[i])
            {
            case '+':
                ans = val2 + val1;
                break;
            case '-':
                ans = val2 - val1;
                break;
            case '*':
                ans = val2 * val1;
                break;
            case '/':
                ans = val2 / val1;
                break;
            }
            new_push(ans);
        }
        i++;
    }
    peek();
    return 0;
}

void new_push(int a)
{
    if (topper == Max - 1)
    {
        printf("stack overflowing");
    }
    else
    {
        topper++;
        new_st[topper] = a;
    }
}
void peek()
{
    if (topper == -1)
    {
        printf("Stack empty\n");
    }
    else
    {
        printf("%d", new_st[topper]);
    }
}
int new_pop()
{   int y;
    if (topper==-1)
    {
        printf("Stack empty\n");
    }
    else
    {
        y=new_st[topper];
        topper--;
        return y;
    }  
}
void infixtopostfix()
{
    char infix[100];
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