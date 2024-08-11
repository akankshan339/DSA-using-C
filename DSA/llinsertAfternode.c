//CASE 4 : to insert a node after a given node
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
struct Node* linklist_InsertAfterNode(struct Node *head,struct Node *prvnode,int data)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
     ptr->data=data;
    ptr->next=prvnode->next;
   prvnode->next=ptr;
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
head=linklist_InsertAfterNode(head,second,data); //give the node after which u want to insert

printf("linklist After insertion of node after second node\n");
linklist_traverse(head);
    return 0;
    
}