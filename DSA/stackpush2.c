#include<stdio.h>
#define MAX 3 // can increase or decrease the size of stack
//not defining top as gobal variable
int isFull(int stk[],int *top)
{
if(*top>MAX-1)
{
    printf("overflow \n");
return 1;
}
else 
return 0;
}
void push(int stk[],int *top,int val)
{
    if(isFull(stk,top)==1)
    printf("stack is full \n");
    else
{
    (*top)++;
    stk[*top]=val;
}
}
void display(int stk[],int top)
//void display(int stk[])
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
    int stk[MAX],top=-1;
    //for(i=1;i<=4;i++)
    push(stk,&top,12);
    push(stk,&top,22);
    push(stk,&top,32);
    push(stk,&top,42);
    push(stk,&top,52);
    display(stk,top); //necessary to pass top to display func while callling bcz it is not a global variable here.
    return 0;
}