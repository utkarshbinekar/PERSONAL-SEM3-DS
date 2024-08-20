#include <stdio.h>
#include <ctype.h>
#define Max 10
int st[Max];
int top = -1;

void push(int);
int pop();
void peek();

int main()
{
    char exp[100];
    int i, val1, val2, ans;
    printf("Enter the expression:\n");
    scanf("%s",exp);
    i = 0;
    while (exp[i]!= '\0')
    {
        if (isdigit(exp[i]) != 0)
        {
            push(exp[i]-48);
        }
        else
        {
            val1 = pop();
            val2 = pop();
            switch (exp[i])
            {
            case '+':
                ans = val1 + val2;
                break;
            case '-':
                ans = val1 - val2;
                break;
            case '*':
                ans = val1 * val2;
                break;
            case '/':
                ans = val1 /val2;
                break;
            }
            push(ans);
        }
        i++;
    }
    peek();
    return 0;
}

void push(int a)
{
    if(top==Max-1)
    {
        printf("stack overflowing");
    }
    else
    {
        top++;
        st[top]=a;
    }
}
void peek()
{   
    if (top==-1)
    {
        printf("Stack empty\n");
    }
    else{
        printf("%d",st[top]);
    }
}
int pop()
{   int y;
    if (top==-1)
    {
        printf("Stack empty\n");
    }
    else
    {
        y=st[top];
        top--;
        return y;
    }
    
}

