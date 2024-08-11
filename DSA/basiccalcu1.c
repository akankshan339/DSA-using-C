//basic calculator for + - * /
#include <stdio.h>
#include <string.h>
#include <ctype.h>
# define max 30

void push1(int stk1[], int val,int *top1) {
    if(*top1 >=max-1)
    printf("Stack is Full \n");
    else
    {
    (*top1)++;
    stk1[*top1] = val;
}
}

void push2(char stk2[], char val,int *top2) {
    if(*top2 >=max-1)
    printf("Stack is Full \n");
    else
    {
    (*top2)++;
    stk2[*top2] = val;
}
}

int pop1(int stk1[],int *top1) {
    if((*top1)== -1)
    {
    printf("Stack is Empty \n");
    return -1;
}
else
{
    int temp = stk1[*top1];
    (*top1)--;
    return temp;
}
}

char pop2(char stk2[],int *top2) {
    if((*top2)== -1)
    {
    printf("Stack is Empty \n");
    return -1;
}
else
{
    char temp = stk2[*top2];
    (*top2)--;
    return temp;
}
}

int operation(int v1, int v2, char opert) {
    int x;
    if (opert == '+') {
        x = v1 + v2;
    } else if(opert =='-') {
        x = v2 - v1;
    }
    else if(opert =='*'){
        x=v2*v1;
    }
    else if(opert =='/'){
        x=v2/v1;
    }
    return x;
}

int main() {
    //stk2 is for pushing parenthesis and operators and stk1 is for putting operands i.e nos
    char str[100], stk1[max], stk2[max];
    int i, v1, v2, j = 0, k = 0, r = 0;
    char opert;
    int top1 = -1;
int top2 = -1;

    printf("Enter the string:- ");
    fgets(str, sizeof(str), stdin);   //OR
    //gets(str);
    //char str[]="30-10-(10";
    int l = strlen(str);

    for (i = 0; i < l; i++)
    {
        char ch = str[i];
        if (str[i] == '(') 
        {
            push2(stk2, str[i],&top2); //push opening ( into stack2
        }
        else if (isdigit(str[i]))
        {
            k = str[i] - '0';
            j = i + 1;
            while (str[j] - '0' >= 0 && str[j] - '0' <= 9) 
            {//condition if three is greater than 1 digit no before operator . e.g 123+53 so to make no 213
                r = k * 10;
                k = r + (str[j] - '0');
                j++;
                i++;
            }
            //after no is formed push in stack1
            push1(stk1,k,&top1);
        }
        else if (str[i] == ')') 
        {  //if closing ')' then pop from stack2 until get an '('
            while (stk2[top2] != '(')
            { 
                opert = pop2(stk2,&top2); //poping operator
                v1 = pop1(stk1,&top1); // poping no from stack1
                v2 = pop1(stk1,&top1); //poping no from stack1
                int x = operation(v1, v2, opert); //applying operation on both nos
                push1(stk1, x,&top1); //push the resuklt into stack1
            }
            pop2(stk2,&top2); // Remove the '('
        }
        else if (str[i] == '+' ||str[i]== '-'||str[i]=='*'||str[i]=='/')
        {
          while(top2!= -1 && (stk2[top2] == '+' || stk2[top2]== '-'||stk2[top2] == '*')||stk2[top2]== '/') {
                opert = pop2(stk2,&top2);
                v1 = pop1(stk1,&top1);
                v2 = pop1(stk1,&top1);
                int x = operation(v1, v2, opert);
                push1(stk1, x,&top1);
            }
            push2(stk2, str[i],&top2);
        }
    }//for close

    while (top2 != -1) {
        opert = pop2(stk2,&top2);
        v1 = pop1(stk1,&top1);
        v2 = pop1(stk1,&top1);
        int x = operation(v1, v2, opert);
        push1(stk1, x,&top1);
    }

    int res = stk1[top1];
    
    printf("Result is :%d ", res);

    return 0;
}
