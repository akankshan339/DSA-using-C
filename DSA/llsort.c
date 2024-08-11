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
////insertion from End
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
void sort(node **head)
{
    node *ptr,*cptr;
    ptr=*head;
    while (ptr!=NULL)
    {
        cptr=ptr->next;
        while (cptr!=NULL)
        {
            if(ptr->data > cptr->data)
            {
                int temp=ptr->data;
                ptr->data=cptr->data;
                cptr->data=temp;
            }
            cptr=cptr->next;
        }
        ptr=ptr->next;
    }
    }

int main()
{
    node *head=NULL;
    insertNodeEnd(&head,10);
    insertNodeEnd(&head,8);
    insertNodeEnd(&head,15);
    insertNodeEnd(&head,2);
    insertNodeEnd(&head,50);
    insertNodeEnd(&head,25);
    printf("Before sorting \n");
    printList(head);
    sort(&head);
    printf("After sorting \n");
    printList(head);
}