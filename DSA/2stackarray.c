//WACP to implement 2 stacks through single array
#include<stdio.h>
# define max 10
void push1(int stk[],int *top1,int *top2,int val1)
{
    //if(*top1==max/2-1)
    if(top1==top2)
    printf("Stack is full \n");
    else
    {
        (*top1)++;
        stk[*top1]=val1;
    }
}
    void push2(int stk[],int *top2,int *top1,int val2)
    {
    //if(*top2==max-1)
     if(top1==top2)
    printf("Stack is full \n");
     else
    {
        (*top2)--;
        stk[*top2]=val2;
    }
}
/*int pop1(int stk[],int *top1)
{
    if(*top1==-1)
    {
    printf("Stack is Empty \n");
    return -1;
}
else
{
    int temp=stk[*top1];
    (*top1)--;
    return temp;
}
}
int pop2(int stk[],int *top2)
{
    if(*top2==max)
    {
    printf("Stack is Empty \n");
    return -1;
}
else
{
    int temp=stk[*top2];
    (*top2)++;
    return temp;
}
}*/
void display1(int stk[],int top1)
{
    int i=top1;
    while(i>-1)
    {
        printf("%d \n",stk[i]);
         i--;
    }
}
void display2(int stk[],int top2)
{
    int i=top2;
     //  while(i<10)
    // {
    //     printf("%d \n",stk[i]);
    //      i++;
    // }
    while(i>-1)
    {
        printf("%d \n",stk[i]);
         i--;
    }
}
int main()
{
   int top1=-1,top2=max,stk[max],val1,val2;
    for(int i=0;i<5;i++)
    {
        printf("Enter the values in stack1 and stack 2 :\n");
        scanf("%d%d",&val1,&val2);
        push1(stk,&top1,&top2,val1);
        push2(stk,&top2,&top1,val2);
    }
    printf("Stack1 is :\n");
    display1(stk,top1);
    printf("Stack2 is :\n");
    display2(stk,top2);
   // int w=pop1(stk,&top1);
   // int x=pop2(stk,&top2);
  /*  int v=pop(stk,&top);
    if(v!=-1)
    {
    printf("poped value: %d\n",v);
    }
    else
    printf("Underflow\n");
    printf("Stack after poping\n");
    display(stk,top);*/
   /* printf("poped value from stack1 and stack 2: %d%d\n",w,x);
     printf("Stack1 is :\n");
    display1(stk,top1);
    printf("Stack2 is :\n");*/
    
    return 0;
    
}
