#include <stdio.h>
#include <ctype.h>
 
#define MAX 100
 
char stack[MAX];
int top = -1;
char ch[MAX];
int i = -1;
char c;
 
int s[MAX];
int top2 = -1;
 
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = ch;
}
 
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}
 
int priority(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}
 
void infixToPostfix(char* exp) {
    char* e = exp;
    char x;
 
    printf("Postfix Expression : ");
 
    while (*e != '\0') {
        if (isdigit(*e)) {
            
            while (isdigit(*e)) {
                printf("%c", *e);
                ch[++i] = *e;
                e++;
            }
          
            ch[++i] = ' ';
        } else if (*e == '(') {
            push(*e);
            e++;
        } else if (*e == ')') {
            while ((x = pop()) != '(') {
                printf("%c", x);
                ch[++i] = x;
                ch[++i] = ' ';
            }
            e++;
        } else {
            while (top != -1 && priority(stack[top]) >= priority(*e)) {
                c = pop();
                printf("%c", c);
                ch[++i] = c;
                ch[++i] = ' ';
            }
            push(*e);
            e++;
        }
    }
 
    while (top != -1) {
        c = pop();
        printf("%c", c);
        ch[++i] = c;
        ch[++i] = ' ';
    }
 
    ch[++i] = '\0';
 
    printf("\n");
}
 
void pushInt(int value) {
    if (top2 == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s[++top2] = value;
}
 
int popInt() {
    if (top2 == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return s[top2--];
}
 
int evaluatePostfix(char *expression) {
    while (*expression) {
        if (isspace(*expression)) {
            expression++;
        } else if (isdigit(*expression)) {
            int num = 0;
            while (isdigit(*expression)) {
                num = num * 10 + (*expression - '0');
                expression++;
            }
            pushInt(num);
        } else if (*expression == '+' || *expression == '-' || *expression == '*' || *expression == '/') {
            int right = popInt();
            int left = popInt();
            int result;
 
            switch (*expression) {
                case '+':
                    result = left + right;
                    break;
                case '-':
                    result = left - right;
                    break;
                case '*':
                    result = left * right;
                    break;
                case '/':
                    result = left / right;
                    break;
                default:
                    printf("Invalid operator %c\n", *expression);
                    return -1;
            }
            pushInt(result);
            expression++;
        } else {
            printf("Invalid input.\n");
            return -1;
        }
    }
    return popInt();
}
 
int main() {
    char exp[MAX];
 
    printf("Enter Expression : ");
    scanf("%s", exp);
 
    infixToPostfix(exp);
    printf("Postfix expression is : %s\n", ch);
 
    int res = evaluatePostfix(ch);
    printf("ans: %d\n", res);
 
    return 0;
}