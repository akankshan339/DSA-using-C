// Reverse singly link list when insertion from first using recursion
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
void insert(node **head, int val) // insertion from first
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
        temp->next = *head;
        *head = temp;
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

//reverse Linked list using recusion
void reverseLinkedList(node **head) 
{
    node *prv = NULL;
    node *curr;
    curr = *head;  
    reverse(head,curr,prv);
    //reverse(head,*head,prv);
}

    void reverse(node **head,node *curr,node *prv) 
    {
        if (curr==NULL) //Base case
        {
        *head=prv;
        return;
    }
    node *forward =curr->next;
    reverse(head,forward, curr); //recursion
    curr->next=prv;
    }        

int main()
{
    node *head = NULL;
    int val, n;
    printf("How many nodes:\n");
    scanf("%d", &n);
    printf("Enter data in link list :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insert(&head, val);
    }
    display(head);
    printf("\nReversed list using recursion :\n");
    reverseLinkedList(&head);
    display(head);
    return 0;
}