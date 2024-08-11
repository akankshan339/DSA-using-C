#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node* next;
};
typedef struct node node;
node* head=NULL;
void insert(int v) {
    node* temp;
    temp=(node*)malloc(sizeof(node));
    temp->info=v;
    if(head==NULL)         {
        head=temp;
        head->next=NULL;    }
    else {
        temp->next=head;
        head=temp;
    }}
int delete1() {
    if(head==NULL) {
        printf("stack is empty");
        return -1;
    }
    else  {
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        int x=temp->info;
        free(temp);
        return x;
    }}
void display() {
    node* temp=head;
    while(temp) {
        printf("%d\n",temp->info);
        temp=temp->next;
    }}
int main() {
    printf("Name: Akanksha Negi\nSec: A1\nRoll no: 04");
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    printf("\nThe original elements in the stack are :-\n");
    display();
    int x=delete1();
    printf("The elements after deleting the top value are :-\n");
    display();
    printf("The deleted element is : %d",x);
}
