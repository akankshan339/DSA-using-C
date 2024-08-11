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
int main()
{
    //creating a link list of 3 nodes

//allocate memory for nodes in linklist in heap
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
linklist_traverse(head); // head is a ptr pointing to first node ,,calling func
    return 0;
    
}