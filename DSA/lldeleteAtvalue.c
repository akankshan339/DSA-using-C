//CASE 4: delete a node with a given value,1st occurance of node with that value 
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void linklist_traverse(struct Node *ptr)
{
while(ptr!=NULL)
{
    printf("Data is : %d\n",ptr->data);
    ptr=ptr->next;
}
}
struct Node* deleteValue(struct Node *head,int value)
{//func will not work for value at index 0 i.e first node
struct Node *p=head;
struct Node *q=head->next;
while(q->data!=value && q->next!=NULL)
{//it may happen that value may no present in L.L then p reaches to NULL 
    p=p->next;
    q=q->next;
}
if(q->data==value)
{
p->next=q->next;
free(q);
}
return head;
}
int main()
{
    struct Node *head;   
    struct Node *first;
    struct Node *second;
    struct Node *third; 
head=(struct Node *)malloc(sizeof(struct Node));
second=(struct Node *)malloc(sizeof(struct Node));
third=(struct Node *)malloc(sizeof(struct Node));

head->data=7;
head->next=second; 
second->data=11;
second->next=third;   
third->data=66; 
third->next=NULL;  
printf("Linkedlist before deletion \n");
linklist_traverse(head); 

int value;
printf("Enter the value of node to be deleted \n");
scanf("%d",&value);
head=deleteValue(head,value);

printf("Link list after deletion of node with value %d is \n",value);
linklist_traverse(head); 
    return 0;
    
}