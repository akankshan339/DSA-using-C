//sort singlylink list 
# include<stdio.h>
# include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
void insert(node **head,int val) //insertion from first, the one we inserted at last  prints at first
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=val;
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;
      (* head)->next=NULL;
    }
    else
    {
        temp->next=*head;
        *head=temp;
    }
}
//sorting of linklist 
void sortList(node **head)
{
    node *ptr1=*head;
    node *ptr2;
    while (ptr1->next!=NULL)
    {
        ptr2=ptr1->next;
        while(ptr2!=NULL)
        {
    if(ptr1->data > ptr2->data)
    {
        int t =ptr1->data;
        ptr1->data=ptr2->data;
        ptr2->data=t;
    }
    ptr2=ptr2->next;
    }
    ptr1=ptr1->next;
    }
}
void display(node *head)
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    node *head=NULL;
    int val,n;
    printf("How many nodes:\n");
    scanf("%d",&n);
    printf("Enter data in link list :\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&val);
    insert(&head,val);
    }
    display(head);
    sortList(&head);
    printf("\nSorted list:\n");
    display(head);
}