#include<stdio.h>
# define max 10
void push(int stk[],int *top,int val)
{
    if(*top==max-1)
    printf("Stack is full \n");
    else
    {
        (*top)++;
        stk[*top]=val;
    }
}
int pop(int stk[],int *top)
{
    if(*top==-1)
    {
    printf("Stack is Empty \n");
    return -1;
}
else
{
    int temp=stk[*top];
    (*top)--;
    return temp;
}
}
void display(int stk[],int top)
{
    int i=top;
    while(i>-1)
    {
        printf("%d \n",stk[i]);
        i--;
    }
}
int main()
{
    int top=-1,stk[max],val;
    for(int i=0;i<2;i++)
    {
        printf("Enter the value in stack :\n");
        scanf("%d",&val);
        push(stk,&top,val);
    }
    printf("Stack is :\n");
    display(stk,top);
    int w=pop(stk,&top);
    int x=pop(stk,&top);
    int v=pop(stk,&top);
    if(v!=-1)
    {
    printf("poped value: %d\n",v);
    }
    else
    printf("Underflow\n");
    printf("Stack after poping\n");
    display(stk,top);
    return 0;
}
