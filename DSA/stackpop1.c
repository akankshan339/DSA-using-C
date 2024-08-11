#include<stdio.h>
#define MAX 5 // can increase or decrease the size of stack
int top=-1;  //top as a global variable

int isFull(int stk[]) //returning value data type int
{
if(top>MAX-1)
{
    printf("overflow \n");
return 1;
}
else 
return 0;
}

int isEmpty(int stk[]) 
{
    if(top==-1)
    {
    printf("stack Underflow \n ");
    return 1;
    }
}
void push(int stk[],int val)  //returning no vlaue data type void
{
    if(isFull(stk)==1)
    printf("stack is full \n");
    else
{
    top++;
    stk[top]=val;
}
}
int pop(int stk[]) //returning poped value data type int
{
if(isEmpty(stk)==1)
return 1;
else
{
    int temp=stk[top];
    top--;
    return temp;
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
    printf("enter the values to be put into stack \n");
    int val,i;
    for(i=1;i<=4;i++)
    {
scanf("%d",&val);
push(stk,val);
    }
    // push(stk,12);
    // push(stk,22);
    // push(stk,32);
    // push(stk,42);
    // push(stk,52);
    printf("before pop :\n");
    display(stk);  //optional to pass top while calling bcz top is a global variable 
    int no=pop(stk);
    if(no==1)
    printf("underflow \n");
    else
    printf("poped value : %d \n",no);
    //printf("stack after poping \n");
    display(stk);
return 0;
}