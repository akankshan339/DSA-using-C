//given head of linklst value at each node is either 0,1 linklist holds binary of no and return the decimal value of linklist
//eg [101] otp 5 , eg [1100] otp 12 
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
int BinaryToDecimal(node *head)
{
 node *ptr=head;
 int no=0,digit,count=0,deci=0;
    while(ptr!=NULL)
    {
      digit=ptr->data;
      no=no*10+digit; //it will form a no of data in all nodes of list 
        ptr=ptr->next;
    }
    while(no!=0)
    {
        digit=no%10;
        deci=deci+digit*pow(2,count);
        count++;
        no=no/10;
    }
    return deci;
}

int main()
{
    node *head=NULL;
    int key;
    insertNodeEnd(&head,1);
    insertNodeEnd(&head,1);
    insertNodeEnd(&head,0);
    insertNodeEnd(&head,0);
    //insertNodeEnd(&head,1);
    //insertNodeEnd(&head,1);
    //insertNodeEnd(&head,1);
    printList(head);
    int deci=BinaryToDecimal(head);
    printf("decimal equivalent of binary no formed by link list %d\n",deci);
   
return 0;

}