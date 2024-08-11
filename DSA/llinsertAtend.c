//CASE 3 : to insert a node at end of linkedlist
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
//this func will not work for index=0 //i.e insert at begining
struct Node* linklist_InsertAtEnd(struct Node *head,int data)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head;   //this p will move at a given index-1
    while (p->next!=NULL)
    {
       p=p->next;
       }
     ptr->data=data;
     p->next=ptr;
    ptr->next=NULL;
   
// return ptr; //this prints L.L from the given index
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
printf("before insertion \n");  
linklist_traverse(head); 

int data;
printf("Enter the data to be stored at End of linkedlist \n");
scanf("%d",&data);

head=linklist_InsertAtEnd(head,data);

printf("linklist After insertion of node at end \n");
linklist_traverse(head);
    return 0;
    
}