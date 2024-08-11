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

int linklistMakeNo(node *head)
{
    node *ptr=head;
 int no=0,digit,count=0,deci=0;
    while(ptr!=NULL)
    {
      digit=ptr->data;
      no=no*10+digit; //it will form a no of data in all nodes of list 
        ptr=ptr->next;
    }
    return no;
}
int main()
{
    node *head1=NULL ,*head2=NULL,*head3=NULL;
    int d,n1,n2,sum=0;
    insertNodeEnd(&head1,5);
    insertNodeEnd(&head1,6);
    insertNodeEnd(&head1,3);
    insertNodeEnd(&head2,8);
    insertNodeEnd(&head2,4);
    insertNodeEnd(&head2,2);
    printf("List 1: ");
    printList(head1);
    printf("List 2: ");
    printList(head2);
    n1=linklistMakeNo(head1); //563
    n2=linklistMakeNo(head2); //842
    sum=n1+n2;               //1405
    while(sum!=0)
    {
        d=sum%10;
        insertNodeFront(&head3,d);
        sum=sum/10;
    }
    printf("List 3: ");
    printList(head3);
return 0;

}