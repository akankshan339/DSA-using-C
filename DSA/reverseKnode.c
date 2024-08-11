// Reverse first k nodes of singly link list when insertion from End
// reverse a LinkList head->1-> 2-> 3-> 4-> 5-> 6-> 7-> 8-> NULL
// reverse list when k=2    2-> 1-> 4-> 3-> 6-> 5-> 8-> 7-> NULL
// reverse list when k=3    3-> 2-> 1-> 6-> 5-> 4-> 8-> 7-> NULL
// reverse list when k=4    4-> 3-> 2-> 1-> 8-> 7-> 6-> 5-> NULL
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
void insertEnd(node **head, int val) // insertion from end
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
        // (* head)->next=NULL;
    }
    else
    {
        node *ptr;
        ptr=*head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }

        ptr->next = temp;
        //*head = temp;
    }
}

void display(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

node *reverseKnodes(node *head,int k)
{
   if(head==NULL) //base case
   {
    printf("Nothing to display in the linked list \n");
    return NULL;
   }
   int count=1;
   node *prv,*curr,*forward;
   prv=NULL;
   forward=NULL;
   curr=head;
   while(curr!=NULL && count<=k)
   {
    forward=curr->next;
    curr->next=prv;
    prv=curr;
    curr=forward;
    count++;
}
if(forward!=NULL)
{
//reverseKnodes(&forward,k);  //recursion
head->next=reverseKnodes(forward,k);  //recursion
}
return prv;
}

int main()
{
    node *head = NULL;
    int val, n,k;
    printf("How many nodes:\n");
    scanf("%d", &n);
    printf("Enter data in link list :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insertEnd(&head, val);
    }
    display(head);
    printf("\nEnter number (k) upto how much nodes to be reversed \n");
    scanf("%d",&k);
    head=reverseKnodes(head,k);
    if(head==NULL)
    printf("Linked list is empty \n");
    else
    {
    printf("\nReversed k nodes list:\n");
    display(head);
    }
}