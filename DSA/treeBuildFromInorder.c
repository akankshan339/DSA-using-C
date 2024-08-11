//given 2 integer array inorder and postorder traversals .construct and return binary tree.
//input inorder=[9,3,15,20,7] postorder=[9,15,7,20,3]  output :[3,9,20,null,null,15,7]
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct node {
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node node;

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1;
}

node* buildTreeHelper(int inorder[], int inStart, int inEnd, int postorder[], int* postIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    // Create the current root node
    node* root = (node*)malloc(sizeof(struct node));
    int val = postorder[(*postIndex)];
    (*postIndex)--;
    root->data =val;
    root->left = NULL;
    root->right = NULL;

    // Find the index of the root in inorder
    int inIdx = search(inorder, inStart, inEnd, val);

    // Recursively build the right and left subtrees
    root->right = buildTreeHelper(inorder, inIdx + 1, inEnd, postorder, postIndex);
    root->left = buildTreeHelper(inorder, inStart, inIdx - 1, postorder, postIndex);

    return root;
}

node* buildTree(int inorder[], int inSize, int postorder[], int poSize) {
    if (inSize == 0 || poSize == 0) {
        return NULL;
    }

    int postIndex = poSize - 1;
    return buildTreeHelper(inorder, 0, inSize - 1, postorder, &postIndex);
}

// Function to print the inorder traversal of the tree (for testing)
void preorderTraversal(node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        //printf("%d ", root->data);     //for testing inorder
        preorderTraversal(root->right);
    }
}

int main() {
    int inSize;
    printf("Enter the size of the inorder traversal: ");
    scanf("%d", &inSize);
    
    int inorder[inSize];   //inorder array
    printf("Enter the elements of the inorder traversal: ");
    for (int i = 0; i < inSize; i++)
    {
        scanf("%d", &inorder[i]);
    }

    int poSize;
    printf("Enter the size of the postorder traversal: ");
    scanf("%d", &poSize);
    
    int postorder[poSize];      //postorder array

    printf("Enter the elements of the postorder traversal: ");
    for (int i = 0; i < poSize; i++)
    {
        scanf("%d", &postorder[i]);
    }

    node* root = buildTree(inorder, inSize, postorder, poSize);

    // Print the inorder traversal of the constructed tree (for verification)
    printf("Preorder Traversal: ");
    preorderTraversal(root);        //3 9 20 15 7
    return 0;
}