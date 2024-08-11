#include<stdio.h>
#define MAX 5 // can increase or decrease the size of stack
int top=-1; //top as a global variable
int isFull(int stk[])
{
if(top>MAX-1)
{
    printf("overflow \n");
return 1;
}
else 
return 0;
}
void push(int stk[],int val)
{
    if(isFull(stk)==1)
    printf("stack is full \n");
    else
{
    top++;
    stk[top]=val;
}
}
void display(int stk[])
{
    int i=top; // top can be further used anywhere
    while(i>-1)
    {
        printf("%d \n",stk[i]);
        i--;
    }
}
int main()
{
    int stk[MAX];
    //for(i=1;i<=4;i++)
    push(stk,12);
    push(stk,22);
    push(stk,32);
    push(stk,42);
    push(stk,52);
    display(stk);  //optional to pass top while calling bcz top is a global variable 
return 0;
}