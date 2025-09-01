
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
int isEmpty() { return top == -1; }

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

void infixToPostfix(char *exp)
{
    char *e = exp;
    while (*e != '\0')
    {
        if (isalnum(*e))
        { // operand
            printf("%c", *e);
        }
        else if (*e == '(')
        {
            push(*e);
        }
        else if (*e == ')')
        {
            while (!isEmpty() && peek() != '(')
                printf("%c", pop());
            pop(); // remove '('
        }
        else
        { // operator
            while (!isEmpty() && precedence(peek()) >= precedence(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }
    while (!isEmpty())
        printf("%c", pop());
}

int main()
{
    char exp[] = "a*(b-c)+e-f-/g+h%2";
    printf("Infix: %s\nPostfix: ", exp);
    infixToPostfix(exp);
    printf("\n");
    return 0;
}
