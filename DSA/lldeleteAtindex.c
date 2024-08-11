//CASE 2 : deleting node at a given index
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
struct Node* deleteAtIndex(struct Node* head,int index)
{ //this func will not work for index=0 
struct Node *p=head; //p is at prv node of index that is to be deleted(index-1)
struct Node *q=head->next; //q is at node of the index to be deleted 
int i=0;
while(i!=index-1) //  loop will run 0  times for index=1
{
     p=p->next;
     q=q->next; //till q reach at that index node
    i++;
 }//after completing this while loop p will at index-1 node
 
//OR use for loop
// for(i=0;i<index-1;i++) //for index 1 loop will run 0 times 
// {
// p=p->next;
// q=q->next;
// }
p->next=q->next;
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
printf("Linkedlist before deletion \n");
linklist_traverse(head); 

int index;
printf("Enter the index which of node to be deleted \n");
scanf("%d",&index);
head=deleteAtIndex(head,index);

printf("Link list after deletion of node at index %d \n",index);
linklist_traverse(head); 
    return 0;
    
}