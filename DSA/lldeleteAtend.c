//CASE 3 : to delete a node from end of linkedlist
# include<stdio.h>
# include<stdlib.h>
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

struct Node* linklist_DeleteAtEnd(struct Node *head)
{
    struct Node *p=head;
     struct Node *q=head->next;
    while (q->next!=NULL) 
    {
       p=p->next; //p will pt to one prv node at last
       q=q->next;  //q is pointing to last node
       }
     p->next=NULL;
   free(q);
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
printf("before deletion \n");  
linklist_traverse(head); 

head=linklist_DeleteAtEnd(head);
//head=linklist_DeleteAtEnd(head);//calling this func 2 times delete2 nodes from end
printf("linklist After deletion of node at end \n");
linklist_traverse(head);
    return 0;
    
}