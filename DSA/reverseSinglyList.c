// Reverse singly link list when insertion from first and insertion from end
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
void insertFirst(node **head, int val) // insertion from first
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
        ptr = *head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
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
// reverse a LinkList head->1-> 2-> 3-> 4-> 5-> NULL
// reverse list   NULL<- 1<- 2<- 3<- 4<- 5<-head
void reverseList(node **head) // iterative method time complexity O(n)
{
    node *prv = NULL;
    node *forward, *curr;
    curr = *head;                               // curr is pointing to head node initally and forward is pointing head next
    if (*head == NULL || (*head)->next == NULL) // case when nothing is present in linklist or only 1 element is present
    {
        printf("nothing is present in linklist or only 1 element is present\n");
    }
    else
    {
        // curr=*head;
        while (curr != NULL)
        {
            forward = curr->next; // if don't use forward can't excess remaining list after head
            curr->next = prv;
            prv = curr;
            curr = forward;
        }
    }
    *head = prv; // Update the head to the new first node.
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
        // insertFirst(&head, val);
        insertEnd(&head, val);
    }
    display(head);
    reverseList(&head);
    printf("\nReversed list:\n");
    display(head);
    return 0;
}