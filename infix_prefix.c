#include <stdio.h>
#include <string.h>
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

// Helper: reverse string
void reverse(char *exp)
{
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++)
    {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

// Convert infix -> postfix
void infixToPostfix(char *exp, char *result)
{
    char *e = exp;
    int k = 0;
    while (*e != '\0')
    {
        if (isalnum(*e))
            result[k++] = *e;
        else if (*e == '(')
            push(*e);
        else if (*e == ')')
        {
            while (!isEmpty() && peek() != '(')
                result[k++] = pop();
            pop();
        }
        else
        {
            while (!isEmpty() && precedence(peek()) > precedence(*e))
                result[k++] = pop();
            push(*e);
        }
        e++;
    }
    while (!isEmpty())
        result[k++] = pop();
    result[k] = '\0';
}

void infixToPrefix(char *exp, char *result)
{
    reverse(exp);
    for (int i = 0; exp[i]; i++)
    {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }
    infixToPostfix(exp, result);
    reverse(result);
}

int main()
{
    char exp[] = "a*(b-c)+d*b";
    char prefix[MAX];
    infixToPrefix(exp, prefix);
    printf("Infix: %s\nPrefix: %s\n", exp, prefix);
    return 0;
}
