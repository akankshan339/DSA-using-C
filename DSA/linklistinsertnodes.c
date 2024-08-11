#include<stdio.h>  
#include<stdlib.h>  
void beginsert(int);  
struct Node  
{  
    int data;  
    struct Node *next;  
};  
struct Node *head;  
void printlist(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Data is : %d\n",ptr->data);
ptr=ptr->next; 
    }
}
void main ()  
{  
    struct Node *head;  
    int choice,item;  
    do   
    {  
        printf("\nEnter the item which you want to insert?\n");  
        scanf("%d",&item);  
        beginsert(item);  
        printf("\nPress 0 to insert more ?\n");  
        scanf("%d",&choice);  
    }while(choice == 0); 
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node *));  
    printlist(head);
}  
void beginsert(int item)  
    {  
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node *));  
        if(ptr == NULL)  
        {  
            printf("\nOVERFLOW\n");  
        }  
        else  
        {  
            ptr->data = item;  
            ptr->next = head;  
            head = ptr;  
            printf("\nNode inserted\n");  
        }  
          
}