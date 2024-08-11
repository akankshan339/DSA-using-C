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
int searchKey(node *head,int key)
{
int count=0;
node*ptr=head;
while(ptr!=NULL)
{
if(ptr->data==key)
count++;
ptr=ptr->next;
}
return count;
}

int main()
{
    node *head=NULL;
    int key;
    insertNodeEnd(&head,1);
    insertNodeEnd(&head,2);
    insertNodeEnd(&head,1);
    insertNodeEnd(&head,2);
    insertNodeEnd(&head,1);
    insertNodeEnd(&head,3);
    insertNodeEnd(&head,1);
    printList(head);
    printf("Enter the key to be searched \n");
    scanf("%d",&key);
    int count=searchKey(head,key);
    printf("the count of serached key is %d\n",count);
return 0;

}