#include <stdio.h>
#include <ctype.h>

#define MAX 100
int stack[MAX];
int top = -1;

void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }

int evaluatePostfix(char* exp) {
    for(int i=0; exp[i]; i++) {
        char ch = exp[i];
        if(isdigit(ch)) {
            push(ch - '0');  // convert char to int
        } else {
            int val2 = pop();
            int val1 = pop();
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
    char postfix[] = "23*21-/53*+"; // from earlier example
    printf("Postfix Expression: %s\n", postfix);
    printf("Result = %d\n", evaluatePostfix(postfix));
    return 0;
}
