#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node* next;
};
typedef struct node node;
void insert(node** f,node** r,int v)
{
    node* temp=NULL;
    temp=(node*)malloc(sizeof(node));
    // if(temp==NULL)
    // {
    //     printf("Overflow");
    // } // no overflow in linklist
   // else
    //{
        temp->info=v;
        temp->next=NULL;
        if(*r==NULL)
        {
            *r=temp;
            *f=temp;
        }
        else
        {
            (*r)->next=temp;
            *r=temp;
        }
   // }
}
int delete1(node** f,node**r)
{
    int x;
    if(*f==NULL)
    {
        printf("Queue is empty");
        return -1;
    }
    else
    {
        x=(*f)->info;
        if((*f)->next==NULL)
        {
            *f=NULL;
            *r=NULL;
        }
        else
        {
            node* temp=(*f)->next;
            (*f)->next=NULL;
            (*f)=temp;
        }
        return x;
    }
}
void display(node* front,node* rear)
{
    if(front==rear)
    {
        printf("Nothing to display");
    }
    else
    {
        while(front!=rear)
        {
            printf("%d ",front->info);
            front=front->next;
        }
        printf("%d\n",front->info);
    }
}
int main()
{
    node* front=NULL,*rear=NULL;
    printf("Name: Akanksha Negi\nSec: A1\nRoll no: 04\n");
    insert(&front,&rear,10);
    insert(&front,&rear,20);
    insert(&front,&rear,30);
    insert(&front,&rear,40);
    insert(&front,&rear,50);
    printf("The elemnts in the queue are :-\n");
    display(front,rear);
    int x=delete1(&front,&rear);
    printf("The elements after deletion from queue are :-\n");
    display(front,rear);
    printf("The deleted element is : %d",x);
}
