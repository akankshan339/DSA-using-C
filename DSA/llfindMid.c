//find middle of linklist
//given 2 nos represented by in 2 linklist retrun sum of 2 nos in form of link list
//Input List 1 : 5->6->3 no: 563  List 2: 8->4->2 no 842 
//Output 1->4->0->5 no 1405  i.e sum=563+842
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
        *head = temp;// If the list is empty, make the new node the head
    }
    else
    {
      node *ptr = *head;  // Traverse to the end of the list and insert the new node
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

node* findMid(node **head)
{
    node *ptr=*head,*p=*head;
    while(ptr->next!=NULL && p->next!=NULL)
    {
        ptr=ptr->next->next;
        p=p->next;
    }
    return p;
}
int main()
{
    node *head=NULL ,*midnode ;
    insertNodeEnd(&head,1);
    insertNodeEnd(&head,2);
    insertNodeEnd(&head,3);
    insertNodeEnd(&head,4);
    insertNodeEnd(&head,5);
   printList(head);
    midnode=findMid(&head);
   printf("Middle of link list is :%d",midnode->data);
return 0;

}