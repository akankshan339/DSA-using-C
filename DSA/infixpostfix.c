// # include<stdio.h>
// # include<string.h>
// int isEmpty(char stk[],int top)
// {
//     if(top==-1)
//     return 1;
//     else
//     return -1;
// }
// void push(char stk,int *top,char ch)
// {
//     if(isFull(stk,top)==1)
//     printf("stack is full \n");
//     else
//     (*top)++;
//     stk[*top]=ch;
// }
// char pop(char stk[],int *top)
// {
//     if(isEmpty(stk,top)==1)
//     {
//     printf("stack is empty \n");
//     return NULL;
// }
//     else
//     {
//     char ch=stk[*top];
//     (*top)--;
//     return ch;
//     }
// }
// int prec(char a)
// {
//     switch(a){
//         case '-':return 1;
//         case '+':return 1;
//         case '*':return 2;
//         case '/':return 2;

//     }
// }
// int main()
// {
//     char str[]="a+b/c-d*e%f",out[]="",stk[15];
//     int i,l,top=-1;
//     l=strlen(str);
//     for(i=0;i<l;i++)
//     {
//         if(str[i]>='a' && str[i]<='z')
//         out=out+str[i];
//         else{
//             if(isEmpty(stk,top)==1)
//             push(stk,&top,str[i]);
//             else
//             {
//                 while(prec(str[i])< prec(stk[top]))
//                 {
//                     out=out+stk[top];
//                     char ch=pop(stk,&top);
//                 }
//                 push(stk,&top,str[i]);
//             }
//         }
//     }
//     printf("%s\n",out);
//     return 0;
// }
#include <stdio.h>
#include <string.h>
# define size 11

int isFull(int top) {
    return top == size - 1; // OR  also put == in this statement
 /* if(top==size-1)  //using this it gives wrong output 
  return 1;
  else
  return -1;*/
}

int isEmpty(int top) {
    return top == -1;
/*   if(top==-1)  //using this it gives wrong output 
  return 1;
  else
  return -1; */
}

void push(char stk[], int *top, char ch) {
    if (isFull(*top)) {
        printf("Stack is full\n");
    } else {
        (*top)++;
        stk[*top] = ch;
    }
}

char pop(char stk[], int *top) {
    if (isEmpty(*top)) {
        printf("Stack is empty\n");
        return '\0'; // Return a null character to indicate an error
    } else {
        char ch = stk[*top];
        (*top)--;
        return ch;
    }
}

int prec(char a) {
    switch (a) {
        case '-':
         return 1;
        case '+':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '%':
            return 2;
    }
    return -1; // Return -1 for other characters (invalid operators)
}

int main() {
    char str[] = "a+b/c-d*e%f", out[size] = "", stk[size];
   // "a*b-c"  postfix out1 =ab*c- postfix out2= abc/+def%-
    int i, l, top = -1;

    l = strlen(str);
    for (i = 0; i < l; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            strncat(out, &str[i], 1); // Append character to 'out' string
        } else {
            if (isEmpty(top) || prec(str[i]) > prec(stk[top])) {
                push(stk, &top, str[i]);
            } else {
                while (!isEmpty(top) && prec(str[i]) <= prec(stk[top])) {
                    char ch = pop(stk, &top);
                    strncat(out, &ch, 1); // Append character to 'out' string
                }
                 push(stk, &top, str[i]);
            }
          //   push(stk, &top, str[i]); writing this line here gives wrong output
        }
    }

    while (!isEmpty(top)) {
        char ch = pop(stk, &top);
        strncat(out, &ch, 1); // Append character to 'out' string
    }

    printf("%s\n", out);

    return 0;
}

