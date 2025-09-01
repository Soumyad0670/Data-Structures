#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
int stack[MAX];
int top = -1;

void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }

int evaluatePrefix(char* exp) {
    int n = strlen(exp);
    for(int i=n-1; i>=0; i--) {
        char ch = exp[i];
        if(isdigit(ch)) {
            push(ch - '0');
        } else {
            int val1 = pop();
            int val2 = pop();
            switch(ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}

int main() {
    char prefix[] = "+/*23-215*53"; // equivalent example
    printf("Prefix Expression: %s\n", prefix);
    printf("Result = %d\n", evaluatePrefix(prefix));
    return 0;
}
