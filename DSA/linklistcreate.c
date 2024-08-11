# include<stdio.h>
# include<stdlib.h>
struct Node{
    int data;
   struct Node *next;//self referencing structrue those structures that have one or more pointers which point to the same type of structure, as their member.
};
int main()
{
    //creating a link list of 3 nodes
// e.g int *ptr=(int *)malloc(sizeof(int));
//allocate memory for nodes in linklist in heap
    struct Node *head;   //head is 1st node is a ptr of data type struct Node store address
    //struct Node *first;
    struct Node *second;
    struct Node *third; 
head=(struct Node *)malloc(sizeof(struct Node));//dynamic memory allocattion in heap
second=(struct Node *)malloc(sizeof(struct Node));
third=(struct Node *)malloc(sizeof(struct Node));
//inserting data  and ptr to next node 
head->data=7;
head->next=second; //link first and second node
second->data=11;
second->next=third;   //link second and third node
third->data=66; 
third->next=NULL;  //terminate last node to NULL

    return 0;
    
}