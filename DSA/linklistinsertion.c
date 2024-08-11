# include<stdio.h>
# include<stdlib.h>
struct Node{
    int data;
   struct Node *next;
    struct Node *new_node;  //self referencing structrue
};
// CASE 1 :insertion of a node in linklist at begining
void linklist_insert(struct Node **head,int nodedata)
{
struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
new_node->data=nodedata; // insert data to new_node
new_node->next=*head;  //new_node is points to address of head or store add of head
*head=new_node;  //assign new_node as head
}
void linklist_print(struct Node *ptr)
{
while(ptr!=NULL)
{
printf("Data is : %d\n",ptr->data);
ptr=ptr->next; //moves ptr to next node until ptr points to null
}
}
int main()
{
    int nodedata;
struct Node *head=(struct Node *)malloc(sizeof(struct Node));
struct Node *second=(struct Node *)malloc(sizeof(struct Node));
struct Node *third=(struct Node *)malloc(sizeof(struct Node));

head->data=7;
head->next=second; 
second->data=11;
second->next=third;   
third->data=66; 
third->next=NULL; 

printf("Linklist before insertion :\n");
linklist_print(head);

printf("Enter data of new node :\n");
scanf("%d",&nodedata);
// Use '&' i.e. address as we need to change head address
linklist_insert(&head,nodedata);
    
    printf("Linklist after insertion of node at first :\n");
    // Don't use '&' as not changing head in printLinkedList operation
    linklist_print(head);
    return 0;
    
}