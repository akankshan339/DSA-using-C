# include<stdio.h>
# define max 10
void enqueue(int q[],int *f,int *r,int val)
{
if(*r==max-1)
printf("queue is full \n");
else{
    if(*f==-1)
    (*f)++;
    (*r)++;
    q[*r]=val;
}
}
int dequeue(int q[],int *f,int *r)
{
    if(*f==-1)
    {
        printf("queue is empty \n");
        return -1;
    }
else
{
    int temp=q[*f];
    if(*f==*r)
    {
        *f=-1;
        *r=-1;
    }
    else
    (*f)++;
    return temp;
}
}
void display(int q[],int f,int r)
{
    for(int i=f;i<=r;i++)
    {
        printf("%d ",q[i]);
    }
}
int main()
{
    int q[max],f=-1,r=-1,n,val;
    printf("Enter the size of queue \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
    printf("enter the value in queue \n");
    scanf("%d",&val);
    enqueue(q,&f,&r,val);
    }
    printf("Queue is :\n");
    display(q,f,r);
    int v=dequeue(q,&f,&r);
    if(v!=-1)
    printf("\n\nDequeued value from queue :%d \n",v);
    else
    printf("queue is empty \n");
    display(q,f,r);
    int x=dequeue(q,&f,&r);
    if(x!=-1)
    printf("Dequeued value from queue :%d \n",x);
    else
    printf("queue is empty \n");
    display(q,f,r);
    int w=dequeue(q,&f,&r);
    if(w!=-1)
    printf("Dequeued value from queue :%d \n",w);
    else
    printf("queue is empty \n");
    printf("Final queue is :\n");
    display(q,f,r);
    return 0;
}