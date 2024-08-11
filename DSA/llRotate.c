//given head of linklist rotate list to right by k places eg. 1->2->3->4->5 k=2 i.e rotate to right by 2 in to shifts
//rotate 1: 5->1->2->3->4  rotate 2: 4->5->1->2->3
//time complexity O(k*N)  k times reach to end and put last node to front
//optimized time complexity=O(N)+ O(N- (N % len)) =O(N) and space complexity O(1)
//if k>len of list eg 12 k=k%len eg 12%5=2 then k=2 i.e 2 rotation
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node node;
//insertion from end
void insertEnd(node **head,int val)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->data=val;
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;
        }
    else{
        node *ptr=*head;
        while(ptr->next!=NULL)
        {
         ptr=ptr->next;
        }
        ptr->next=temp;
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
void rotate(node **head,int k)
{
    int len=0;
    node *ptr=*head ,*p=*head;
    
    if(k==0 || k%k==0 || (*head)==NULL || (*head)->next==NULL)
    {
    return ;
    }
    else
    {
    while(ptr->next!=NULL)
    {
        len++; //after any multiple of size rotation we get original linklist eg.after 5,10,15,20....rotations
        ptr=ptr->next;
        
    }
    ptr->next=*head; //pointing last node to head node
   k=k%len; //in case k >len
   int n=len-k; //5-2=3
    
    while(n>0) //here eg n=3
    {
        p=p->next;
        n--;
    }
   ptr=p->next;
     p->next=NULL;
    }
    *head=ptr;
}
int main()
{
    node *head=NULL;
    int k;
    insertEnd(&head,1);
    insertEnd(&head,2);
    insertEnd(&head,3);
    insertEnd(&head,4);
    insertEnd(&head,5);
    printList(head);
    printf("How many places do you want to rotate :\nEnter the value of k:\n");
    scanf("%d",&k);
    rotate(&head,k);
     printList(head);
    return 0;
}