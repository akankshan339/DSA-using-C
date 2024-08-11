//remove nth node from end and return head eg 1->2->3->4->5  n=2, otp 1->2->3->5
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
//insertion from front
void insertNodeFront(node **head,int val)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->data=val;
    temp->next=NULL;

    if(*head==NULL)
    {
    (*head)=temp;
    (*head)->next=NULL;
    }
    else{
        temp->next=*head;
        *head=temp;
    }
}
//insertion from End
void insertNodeEnd(node **head, int val)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;

    if (*head == NULL)
    {
        // If the list is empty, make the new node the head
        *head = temp;
    }
    else
    {
        // Traverse to the end of the list and insert the new node
        node *ptr = *head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void printList(node *head)
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
        
    }
    printf("\n");
}
void removeNthNode(node **head,int n)
{
node *ptr=*head, *p=*head;
int count=0;
while(ptr!=NULL)
{
    ptr=ptr->next;
    count++; //length of linklist
}
int d=count-n;
if(d==0)
{
  *head=(*head)->next;
  free(p);
}
else
{
while(d!=1)
{
    p=p->next;
    d--;
}
node *del=p->next;
//del->next=NULL;
p->next=p->next->next;
del->next=NULL;
free(del);
}
}

int main()
{
    node *head=NULL;
    int n;
    insertNodeEnd(&head,1);
    insertNodeEnd(&head,2);
    insertNodeEnd(&head,3);
    insertNodeEnd(&head,4);
    insertNodeEnd(&head,5);
    printList(head);
    printf("Enter the pos of node to be removed from end\n");
    scanf("%d",&n);
    removeNthNode(&head,n);
    printf("Linklist after removing %dnd from end is\n",n);
    printList(head);
return 0;

}
