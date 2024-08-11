#include <stdio.h>
#include <string.h>
#include <ctype.h>
//when top declared as global
//stack2 is for pushing parenthesis and operators e.g + -
//stack1 is for pushing nos
int top1 = -1;
int top2 = -1;

void push1(int stk1[], int val) {
    top1++;
    stk1[top1] = val;
}

void push2(char stk2[], char val) {
    top2++;
    stk2[top2] = val;
}

int pop1(int stk1[]) {
    int temp = stk1[top1];
    top1--;
    return temp;
}

char pop2(char stk2[]) {
    char temp = stk2[top2];
    top2--;
    return temp;
}

int operation(int v1, int v2, char op) {
    int x;
    if (op == '+') {
        x = v1 + v2;
    } else {
        x = v2 - v1;
    }
    return x;
}

int main() {
    char str[100], stk1[50], stk2[50];
    int i, v1, v2, j = 0, k = 0, r = 0;
    char op;
    printf("Enter the string:- ");
    fgets(str, sizeof(str), stdin);   //OR
   // gets(str);
    int l = strlen(str);

    for (i = 0; i < l; i++) {
        char ch = str[i];
        if (str[i] == '(') {
            push2(stk2, str[i]);
        } else if (isdigit(str[i])) {
            k = str[i] - '0';
            j = i + 1;
            while (str[j] - '0' >= 0 && str[j] - '0' <= 9) {
                r = k * 10;
                k = r + (str[j] - '0');
                j++;
                i++;
            }
            push1(stk1, k);
        } else if (str[i] == ')') {
            while (stk2[top2] != '(') {
                op = pop2(stk2);
                v1 = pop1(stk1);
                v2 = pop1(stk1);
                int x = operation(v1, v2, op);
                push1(stk1, x);
            }
            pop2(stk2); // Remove the '('
        } else if (str[i] == '+' || str[i] == '-') {
            while (top2 != -1 && (stk2[top2] == '+' || stk2[top2] == '-')) {
                op = pop2(stk2);
                v1 = pop1(stk1);
                v2 = pop1(stk1);
                int x = operation(v1, v2, op);
                push1(stk1, x);
            }
            push2(stk2, str[i]);
        }
    }

    while (top2 != -1) {
        op = pop2(stk2);
        v1 = pop1(stk1);
        v2 = pop1(stk1);
        int x = operation(v1, v2, op);
        push1(stk1, x);
    }

    int res = stk1[top1];
    printf("%d ", res);

    return 0;
}
