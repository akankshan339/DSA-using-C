//WACP to create 2 linklists positive & negative from Original linkedlist, so that positive linkedlist contains all positive elements
//and negative linked list contains negative elements. Positive and negative linked lists should use the node of existing original linked list.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;
void insert(Node** head, int value) {
     Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
         Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void sepratePosNeg(Node* head,Node** positiveHead, Node** negativeHead) {
     Node* temp = head;
    while (temp != NULL) 
    {
        if (temp->data >= 0) {
            insert(positiveHead, temp->data);
        } else {
            insert(negativeHead, temp->data);
        }
        temp = temp->next;
    }
}

void displayLinkedList(struct Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
   Node* originalHead = NULL;
   Node* posHead = NULL;
   Node* negHead = NULL;
    insert(&originalHead, 10);
    insert(&originalHead, -5);
    insert(&originalHead, 20);
    insert(&originalHead, -15);
    insert(&originalHead, 30);
    sepratePosNeg(originalHead, &posHead, &negHead);
    printf("Original Linked List: ");
    displayLinkedList(originalHead);
    printf("Positive Linked List: ");
    displayLinkedList(posHead);
    printf("Negative Linked List: ");
    displayLinkedList(negHead);

    return 0;
}