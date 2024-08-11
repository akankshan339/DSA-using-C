//Write a C program to craeate a single linked list , like L0 -> L1 -> … -> Ln-1 -> Ln. Write another C fucntion to rearrange the nodes in list 
//so that new formed list is : L0 -> Ln -> L1 -> Ln-1 -> L2-> Ln-2 .You are required to do this in place without altering the nodes’ values.
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node node;

node *newNode(int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void printList(node *head) {
    node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
node *findMiddle(node *head) {
  node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node *reverseList(node *head) {
   node *prev = NULL, *curr = head, *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void rearrangeList(node **head) {
    node *mid = findMiddle(*head);
    node *head1 = *head;
    node *head2 = mid->next;
    mid->next = NULL;
    head2 = reverseList(head2);
    *head = newNode(0);
    node *curr = *head;
    while (head1 != NULL || head2 != NULL) {
        if (head1 != NULL) {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
        if (head2 != NULL) {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }
    *head = (*head)->next; 
}
int main() {
    node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Original list: ");
    printList(head);
    rearrangeList(&head);
    printf("Rearranged list: ");
    printList(head);
return 0;
}