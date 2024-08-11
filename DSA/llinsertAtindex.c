//CASE 2 : to insert a node in between at a particular index
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
struct Node* linklist_InsertIndex(struct Node *head,int data,int index)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head;   //this p will move at a given index-1
    int i=0;
    while (i!=index-1)
    {
       p=p->next;
       i++;
    }
     ptr->data=data;
    ptr->next=p->next;
   p->next=ptr;
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

int data,index;
printf("Enter the data to be stored at begining of linkedlist \n");
scanf("%d",&data);
printf("Enter the index where the node is to be inserted \n");
scanf("%d",&index);
head=linklist_InsertIndex(head,data,index);

printf("linklist After insertion of node at index %d \n",index);
linklist_traverse(head);
    return 0;
    
}