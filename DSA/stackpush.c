#include<stdio.h>
# define MAX 3
int top=-1; // declaring top glovbal variableso cannot be used in other files

void push(int st[],int val)
{
    if(top >= MAX-1)
    {
    printf("stack is full \n");
   // printf("value at top is : ",st[top]);
    }
    else
    {
        top++;
        st[top]=val;
    }
}
int pop(int st[])
{
 if(top==-1)
 {
     printf("stack is empty \n");
 }
 else{
    int temp=st[top];
    top--;
    return temp;
}

}
void display(int st[])
{
    int i=top;
while(i>=0)
{
    printf("%d\n",st[i]);
    i--;
}
}
void replace(int st[],int repvalue)
{
    if(top==-1)
    {
        printf("stack is empty \n underflow \n");
    }
    else
    st[top]=repvalue;
}

int main()
{
    int st[5];
    push(st,4);
    push(st,7);
    push(st,18);
    push(st,90);
    push(st,35);
    display(st);
   int val=pop(st);
    printf("poped value is %d \n",val);
    printf("stack after poping \n");
    display(st);
    printf("replacing top value \n");
    replace(st,145);
    printf("after replacing stack is \n");
    display(st);
    return 0;
}
