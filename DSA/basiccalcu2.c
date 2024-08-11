//basic calculator for +  - * / including parethesis
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 30

void push1(int stk1[], int val, int *top1) {
    if (*top1 >= max - 1)
        printf("Stack is Full\n");
    else {
        (*top1)++;
        stk1[*top1] = val;
    }
}

void push2(char stk2[], char val, int *top2) {
    if (*top2 >= max - 1)
        printf("Stack is Full\n");
    else {
        (*top2)++;
        stk2[*top2] = val;
    }
}

int pop1(int stk1[], int *top1) {
    if ((*top1) == -1) {
        printf("Stack is Empty\n");
        return -1;
    } else {
        int temp = stk1[*top1];
        (*top1)--;
        return temp;
    }
}

char pop2(char stk2[], int *top2) {
    if ((*top2) == -1) {
        printf("Stack is Empty\n");
        return -1;
    } else {
        char temp = stk2[*top2];
        (*top2)--;
        return temp;
    }
}

int operation(int v1, int v2, char opert) {
    int x;
    if (opert == '+') {
        x = v1 + v2;
    } else if (opert == '-') {
        x = v2 - v1;
    } else if (opert == '*') {
        x = v1 * v2;
    } else if (opert == '/') {
        if (v1 != 0) {
            x = v2 / v1;
        } else {
            printf("Division by zero is not allowed.\n");
            return -1; // Return an error code
        }
    }
    return x;
}

int main() {
    char str[100], stk1[max], stk2[max];
    int i, v1, v2, j = 0, k = 0, r = 0;
    char opert;
    int top1 = -1;
    int top2 = -1;

    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);

    int l = strlen(str);
    int balanced = 1; // Flag to track balanced parentheses

    for (i = 0; i < l && balanced; i++) {
        char ch = str[i];
        if (str[i] == '(') {
            push2(stk2, str[i], &top2); // push opening '(' into stack2
        } else if (isdigit(str[i])) {
            k = str[i] - '0';
            j = i + 1;
            while (str[j] - '0' >= 0 && str[j] - '0' <= 9) {
                r = k * 10;
                k = r + (str[j] - '0');
                j++;
                i++;
            }
            push1(stk1, k, &top1); // push the number into stack1
        } else if (str[i] == ')') {
            while (top2 != -1 && stk2[top2] != '(') {
                opert = pop2(stk2, &top2); // popping an operator
                v1 = pop1(stk1, &top1);   // popping a number from stack1
                v2 = pop1(stk1, &top1);   // popping another number from stack1
                int x = operation(v1, v2, opert); // applying operation on both numbers
                if (x == -1) {
                    balanced = 0; // Division by zero error
                    break;
                }
                push1(stk1, x, &top1); // push the result into stack1
            }
            if (top2 == -1 || stk2[top2] != '(') {
                balanced = 0; // Unbalanced parentheses
            } else {
                pop2(stk2, &top2); // Remove the '('
            }
        } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            while (top2 != -1 && ((stk2[top2] == '+' || stk2[top2] == '-') ||
                                  (stk2[top2] == '*' || stk2[top2] == '/'))) {
                opert = pop2(stk2, &top2);
                v1 = pop1(stk1, &top1);
                v2 = pop1(stk1, &top1);
                int x = operation(v1, v2, opert);
                if (x == -1) {
                    balanced = 0; // Division by zero error
                    break;
                }
                push1(stk1, x, &top1);
            }
            push2(stk2, str[i], &top2);
        }
    }

    while (top2 != -1) {
        opert = pop2(stk2, &top2);
        v1 = pop1(stk1, &top1);
        v2 = pop1(stk1, &top1);
        int x = operation(v1, v2, opert);
        if (x == -1) {
            balanced = 0; // Division by zero error
            break;
        }
        push1(stk1, x, &top1);
    }

    if (balanced && top1 == 0) {
        int res = stk1[top1];
        printf("Result is: %d\n", res);
    } else {
        printf("Unbalanced parentheses or invalid expression.\n");
    }

    return 0;
}

