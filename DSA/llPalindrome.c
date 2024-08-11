//given head of linklist check it is palindrome or not return true or false eg head->1->2->2->1 or eg head->1->2->3->2->1
//Case1: check 1st and last node then check 2nd and 2nd lst node and goes on
//here we can move forward but how to move backward from last node ,so reverse half list similar as reverse a full list ,and it will give last ptr
//and pass ptr of mid node,find mid taking 2 ptr 1st moving 1 step and 2nd moving 2 steps until 2nd reach NULL that time 1st will be at mid
//case2:reverse list and then check whether both link list are equal ,
//but this method takes extra space for reversed list ,space=O(n) so case2 not valid 
//also we cannot use arry that also takes extra space
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
void reverse(node **head,node *curr,node *prv) ;

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
node* findMid(node **head)
{
    node *fast,*slow;
    slow=*head;
    fast=*head;
    while(slow!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node* reverseList(node *mid) // iterative method time complexity O(n)
{
    node *prv = NULL;
    node *forward, *curr;
    curr = mid;                               // curr is pointing to head node initally and forward is pointing head next
    if (mid == NULL || (mid)->next == NULL) // case when nothing is present in linklist or only 1 element is present
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
    return prv;
}
void printReverse(node *last)
{
    node *p=last;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
bool isPalindrome(node *head,node *last)
{
   // node *mid=findMid(&head);
  // node *last=reverseList(mid);
    while(last->next!=NULL)
    {
        if((head)->data != last->data)
        return false;
        else
        {
        head=(head)->next;
        last=last->next;
        }
       
    }
    return true;
}
int main()
{
    node *head=NULL,*mid,*last;
    insertNodeEnd(&head,1);
    insertNodeEnd(&head,2);
    insertNodeEnd(&head,3);
    insertNodeEnd(&head,2);
    insertNodeEnd(&head,1);
   
    printList(head);
    mid=findMid(&head);
    last=reverseList(mid);
    //printReverse(last);
    if( isPalindrome(head,last))
    printf("Palindrome List\n");
    else
    printf("Not Palindrome List\n");
return 0;

}
