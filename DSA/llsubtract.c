//Write a C program to create two single linked lists, and then write another function to subtract two
//List1->; 8->9->7->NULL (First Number: 897)
//List2->: 1->4->5->NULL (Second Number: 145)   Output->:752
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
    
int displayLinklist(node *head)
{
    int no=0;
    node *ptr=head;
    while(ptr!=NULL)
    {
        no=no*10+ptr->info;
        printf("%d ",ptr->info);
        ptr=ptr->next;
    }
    printf("\n");
    return no;
}


int main()
{
    node *head1,*head2;
    insertion(&head1,8);
    insertion(&head1,9);
    insertion(&head1,7);

    insertion(&head2,1);
    insertion(&head2,4);
    insertion(&head2,5);
    
    printf("Linklist 1 : ");
    int n1=displayLinklist(head1);
    printf("Linklist 2 : ");
    int n2=displayLinklist(head2);
    printf("After subtracting %d and %d is :%d",n1,n2,(n1-n2));
     return 0;
}



