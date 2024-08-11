//WACP create a single linkedlist then input a value V, partition it such that all nodes less than V come before ,nodes greater than or equal to V remain same
#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
};
typedef struct node node;

void insertion(node **head,int val)
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->info=val;
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;
    }
    else
    {
        node *ptr;
        ptr=*head;
        while(ptr->next!=NULL) //insertion from end
        {
            ptr=ptr->next;
        }
        ptr->next=temp;

    }
}
    
void displayLinklist(node *head)
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->info);
        ptr=ptr->next;
    }
    printf("\n");
}
node* partitionList(node *head, int v) {
    node *lessThanVHead = NULL;
    node *lessThanVTail = NULL;
    node *greaterThanOrEqualVHead = NULL;
    node *greaterThanOrEqualVTail = NULL;

    node *current = head;

    while (current != NULL) {
        if (current->info < v) {
            insertion(&lessThanVHead, current->info);
            if (lessThanVTail == NULL) {
                lessThanVTail = lessThanVHead;
            } else {
                lessThanVTail = lessThanVTail->next;
            }
        } else {
            insertion(&greaterThanOrEqualVHead, current->info);
            if (greaterThanOrEqualVTail == NULL) {
                greaterThanOrEqualVTail = greaterThanOrEqualVHead;
            } else {
                greaterThanOrEqualVTail = greaterThanOrEqualVTail->next;
            }
        }
        current = current->next;
    }

    if (lessThanVTail != NULL) {
        lessThanVTail->next = greaterThanOrEqualVHead;
        return lessThanVHead;
    } else {
        return greaterThanOrEqualVHead;
    }
}


/*node *partitionList(node *head,int v)
{
   
    node *headpre = NULL;   //lessThanVHead
    node *pre = NULL;       //lessThanVTail
    node *headpost = NULL;   //greaterThanOrEqualVHead
    node *post= NULL;       //greaterThanOrEqualVTail

    node *curr = head;

    while (curr != NULL)
    {
        if (curr->info < v) 
        {
            insertion(&headpre, curr->info);
            if (pre == NULL) {
                pre = headpre;
            } else {
                pre = headpre->next;
            }
        }
        else 
        {
            insertion(&headpost, curr->info);
            if (post == NULL) {
                post = headpost;
            } else {
                post = post->next;
            }
        }
        curr = curr->next;
    }

    if (pre != NULL) {
        pre->next = headpost;
        return headpre;
    } else {
        return headpost;
    }
}
*/
int main()
{
    node *head;
    insertion(&head,4);
    insertion(&head,3);
    insertion(&head,2);
    insertion(&head,1);
    insertion(&head,5);
 
    
    printf("Linklist : ");
    displayLinklist(head);
    int v;
    printf("Enter the value of V :");
    scanf("%d",&v);
    head=partitionList(head,v);
    
    printf("After partion of V  : ");
    displayLinklist(head);
    return 0;
}

