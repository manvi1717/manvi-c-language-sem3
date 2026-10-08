#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int priority(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return 0;
}

int main() {
    char infix[100], prefix[100];
    int i, j = 0;
    char ch;

    printf("Enter an infix expression\n");
    scanf("%s", infix);

    for (i = strlen(infix) - 1; i >= 0; i--) {
        ch = infix[i];

        if (ch == ')') {
            push(ch);
        }
        else if (ch == '(') {
            while (top != -1 && stack[top] != ')') {
                prefix[j++] = pop();
            }
            pop();
        }
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            prefix[j++] = ch;
        }
        else {
            while (top != -1 && priority(stack[top]) > priority(ch)) {
                prefix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        prefix[j++] = pop();
    }
    
    prefix[j] = '\0';

    printf("Prefix expression: ");
    for (i = j - 1; i >= 0; i--) {
        printf("%c", prefix[i]);
    }
    printf("\n");

    return 0;
}
