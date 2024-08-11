//insert from end in linklist
# include<stdio.h>
# include<stdlib.h>
struct node{
    int info;
    struct node *next;
};
typedef struct node node;
void insert(node **head,int val)
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->info=val;
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;
    }
    else
    {
        node *ptr;
        ptr=*head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;

    }
    }
    
void display(node *head)
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->info);
        ptr=ptr->next;
    }
}
int main()
{
node *head=NULL;
int n,i,size;
printf("how many nodes to be inserted or size of linklist :\n");
scanf("%d",&size);
for(i=1;i<=size;i++)
{
insert(&head,i);
}
display(head);
return 0;

}