#include<stdio.h>
# define max 5
int isFull(int stk[],int *top)
{
    if(*top > max-1)
    return 1;
    else
    return 0;
}
int isEmpty(int stk[],int *top)
{
    if(*top==-1)
    return 1;
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
int pop(int stk[],int *top)
{
    if(isEmpty(stk,top)==1)
    {
    printf("stack is empty \n");
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
    while (i>-1)
    {
        printf("%d\n",stk[i]);
        i--;
    }
    }
int replace(int stk[],int *top,int val)
{
    int t=stk[*top];
    stk[*top]=val;
    return t;
}
int main()
{
    int stk[max],top=-1;
    push(stk,&top,25);
    push(stk,&top,35);
    push(stk,&top,45);
    push(stk,&top,55);
   // push(stk,&top,65);
    printf("satck before pop :\n");
    display(stk,top);//necessary to pass top to display func while callling bcz it is not a global variable here.
    //int x=pop(stk,&top);
   // int y=pop(stk,&top);
    //int w=pop(stk,&top);
    int v=pop(stk,&top);
    if(v>0)
    printf("poped value : %d \n",v);
    else
    printf("can't pop stack is empty returend %d\n",v);
    printf("satck after pop :\n");
    display(stk,top);

    replace(stk,&top,100);
    printf("after replacing  stack is :\n");
    display(stk,top);
    return 0;

}