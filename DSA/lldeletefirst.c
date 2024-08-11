//CASE 1 : deleting first node of link list
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
struct Node* deleteFirst(struct Node* head)
{
struct Node *ptr=head;
head=head->next;
free(ptr);
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

head=deleteFirst(head);
//head=deleteFirst(head);//calling this func 2 times will delete 2 starting nodes 
printf("Linkes list after deletion of first node \n");
linklist_traverse(head); 
    return 0;
    
}