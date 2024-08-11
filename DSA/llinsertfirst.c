// CASE 1: insert a node at begining 
# include<stdio.h>
# include<stdlib.h>
struct Node{
    int data;
   struct Node *next;  //self referencing structrue
};
void linklist_traverse(struct Node *ptr)
{//traversal of linklist
//ptr of type struct Node pointing to head node,this ptr will traverse whole list& print elements
while(ptr!=NULL)
{
printf("Data is : %d\n",ptr->data);
ptr=ptr->next; //moves ptr to next node until ptr points to null
}
}

struct Node* linklist_InsertFirst(struct Node *head,int data)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;//since ptr is now head node
  // return head;
}
int main()
{
    struct Node *head;   
    struct Node *first;
    struct Node *second;
    struct Node *third; 
head=(struct Node *)malloc(sizeof(struct Node));//dynamic memory allocattion
second=(struct Node *)malloc(sizeof(struct Node));
third=(struct Node *)malloc(sizeof(struct Node));
//inserting data  and ptr to next node 
head->data=7;
head->next=second; 
second->data=11;
second->next=third;   
third->data=66; 
third->next=NULL;
printf("before insertion \n");  
linklist_traverse(head); // head is a ptr pointing to first node ,,calling func
int data;
printf("Enter the data to be stored at begining of linkedlist \n");
scanf("%d",&data);
head=linklist_InsertFirst(head,data);
printf("linklist After insertion of node at first \n");
linklist_traverse(head);
    return 0;
    
}