#include <stdio.h>
#include <stdlib.h>
struct node
{
    node info;
    node *next;
};
typedef struct node node;
//insertion at begining
void insertFirst(node **head, int val)
{

}
//insertion at end
void insertEnd(node **head, int val)
{

}
//deletion from end
int deleteEnd(node **head)
{

}
//deletion from 
int deleteEnd(node **head)
{

}

int main()
{
    node *head = NULL;
    printf("Insert in begining of linklist: \n");
    insertFirst(&head, 10);
    insertFirst(&head, 20);
    insertFirst(&head, 30);
    insertFirst(&head, 40);
    display(head);

    printf("Insert in End of linklist: \n");
    insertEnd(&head, 50);
    insertEnd(&head, 60);
    display(head);

    printf("Delete from begining:\n");
    deleteFirst(&head);
    deleteFirst(&head);
    display(head);

    printf("Delete from End :\n");
    deleteEnd(&head);
    display(head);
}