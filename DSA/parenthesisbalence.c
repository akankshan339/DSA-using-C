#include <stdio.h>
#include <string.h>

#define max 10

int isEmpty(int top) {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(int top) {
    if (top == max - 1) {
        return 1;
    } else {
        return 0;
    }
}

void push(int stk[], int *top, int val) {
    if (isFull(*top) == 1) {
        printf("stack is full \n");
    } else {
        (*top)++;
        stk[*top] = val;
    }
}

int pop(int stk[], int *top) {
    if (isEmpty(*top) == 1) {
        printf("stack is empty \n");
        return -1; // Return a sentinel value to indicate an error.
    } else {
        int temp = stk[*top];
        (*top)--;
        return temp;
    }
}

int main() {
    int top = -1, flag = 0;
    int stk[max];
    char s[20] = "([]}<>)";
    int len = strlen(s);
    int i = 0;

    while (s[i] != '\0') {
        int b = s[i];

        if (b == '(' || b == '{' || b == '[' || b == '<') {
            push(stk, &top, b);
        } else if (b == ')' || b == '}' || b == ']' || b == '>') {
            if (isEmpty(top) == 1) {
                printf("unbalanced \n");
                flag = 1;
                break;
            } else {
                int cb = pop(stk, &top);
                if ((b == ')' && cb != '(') || (b == '}' && cb != '{') || (b == ']' && cb != '[') || (b == '>' && cb != '<')) {
                    printf("unbalanced \n");
                    flag = 1;
                    break;
                }
            }
        }
        i++;
    }

    if (isEmpty(top) && flag == 0) {
        printf("balanced \n");
    } else {
        printf("unbalanced \n");
    }

    return 0;
}
