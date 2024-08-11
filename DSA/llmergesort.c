//given 2 sorted list containing n and m nodes ,retrurn head of merged sorted list 
//list1 1: 5->10->15 list 2: 2->3->20 otp : 2->3->5->10->15->20 hint : use merge sort
//assuming both lists are sorted
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

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

node* sortMergeList(node **head1,node **head2)
{
    node *ptr1=*head1, *ptr2=*head2 ,*ptr3;
    node *dumy=(node*)malloc(sizeof(node));
    ptr3=dumy;
    while(ptr1->next!=NULL && ptr2->next!=NULL)
    {
  if(ptr1->data < ptr2->data )
  {
      ptr3->next=ptr1; //ptr3 will containg address of ptr1 and now points to ptr1
      ptr1=ptr1->next;
  }
  else
  {
      ptr3->next=ptr2; //ptr3 will containg address of ptr2 and points to ptr2
      ptr2=ptr2->next;
  }
  ptr3=ptr3->next;
  }
   while(ptr1!=NULL) //ptr2 reaches to NULL then printing remaining nos of ptr1
    {
      ptr3->next=ptr1; 
      ptr1=ptr1->next;
      ptr3=ptr3->next;
    }
     while(ptr2!=NULL) //ptr1 reaches to NULL then printing remaining nos of ptr2
    {
      ptr3->next=ptr2; 
      ptr2=ptr2->next;
      ptr3=ptr3->next;
    }
      return dumy->next; //if return only dummy it will print 0 also
}
int main()
{
    node *head1=NULL ,*head2=NULL, *dumy;
    int key;
    insertNodeEnd(&head1,5);
    insertNodeEnd(&head1,10);
    insertNodeEnd(&head1,15);
    insertNodeEnd(&head2,2);
    insertNodeEnd(&head2,3);
    insertNodeEnd(&head2,20);
     insertNodeEnd(&head2,30);

    printList(head1);
    printList(head2);
 
   dumy=sortMergeList(&head1,&head2);
   printList(dumy);
return 0;

}
