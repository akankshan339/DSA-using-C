//insertion in a queue i.e enqueue
#include<stdio.h>
# define max 5
void enqueue(int q[],int *front,int *rear,int value)
{
if(*rear=max-1)
printf("Queue is Full \n");
else
{
    if(*front==-1)
    {
        (*front)++;
        (*rear)++;
        q[*rear]=value;
    }
    else
    {
        (*rear)++;
        q[*rear]=value;
    }
}
}
void display(int q[],int rear)
{
    int i=0;
    while(i<= (rear))
    {
        printf("%d \n",q[i]);
        i++;
    }
}
int main()
{
    int q[max],*front=-1,*rear=-1;
    enueue(q,&front,&rear,59);
    enueue(q,&front,&rear,49);
    enueue(q,&front,&rear,29);
    printf("Queue is \n");
    display(q,rear);
    return 0;
}
