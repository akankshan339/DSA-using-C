//Let A and B be two structures of type Linked List. Write a ‘C ’ program to create a new Linked List ‘S’ that contains elements 
//alternately from A and B beginning with the first element of A. If you run out of elements in one of the lists, then append the remaining

#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
};
typedef struct node node;

void insertion(node **head,int val)
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
        while(ptr->next!=NULL) //insertion from end
        {
            ptr=ptr->next;
        }
        ptr->next=temp;

    }
}
    
void displayLinklist(node *head)
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->info);
        ptr=ptr->next;
    }
    printf("\n");
}

node* mergeAlternative(node *head1,node *head2)
{
   node *s = NULL; //new mergerd alternative link list 
    while (head1 != NULL || head2 != NULL) {
        if (head1 != NULL) {
            insertion(&s, head1->info);
            head1 = head1->next;
        }
        if (head2 != NULL) {
            insertion(&s, head2->info);
            head2 = head2->next;
        }
    }
    return s;
}


int main()
{
    node *head1,*head2;
    insertion(&head1,10);
    insertion(&head1,20);
    insertion(&head1,30);
    insertion(&head1,40);
    insertion(&head1,50);

    insertion(&head2,5);
    insertion(&head2,15);
    insertion(&head2,25);
    
    printf("Linklist 1 : ");
    displayLinklist(head1);
    printf("Linklist 2 : ");
    displayLinklist(head2);
    
    node *s=mergeAlternative(head1,head2);
    printf("After merging alternatively : ");
    displayLinklist(s);
    return 0;
}

