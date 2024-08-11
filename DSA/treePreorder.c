//creating and printing a binary tree with lev 0,lev1 lev 2 using Preorder
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};
typedef struct node node;

// Function to build a binary tree
node* buildBinTree(int val) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
    }

// Function to print a binary tree using Preorder traversal
void printTree(node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        printTree(root->left);
        printTree(root->right);
 }
}

int main() {
    node *root = NULL ,*p1,*p2,*p3,*p4,*p5;
    p1=buildBinTree(5); //root node               5
    p2=buildBinTree(10); //left child           /  |
    p3=buildBinTree(15); //right child        10   15
    p4=buildBinTree(20); //left left child   / |
    p5=buildBinTree(25); //left right child 20 25
    p1->left=p2;
    p1->right=p3;
    p1->left->left=p4;
    p1->left->right=p5;
    root=p1;
    printf("Preorder of binary tree is :\n"); //preorder root left right i.e 5 10 20 25 15
    printTree(root);
    return 0;
}



