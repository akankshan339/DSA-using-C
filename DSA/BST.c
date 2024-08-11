//create a BST (i) insertion (ii) deletion a node  (iii)find max and minimum element (iv) Traversal (all) types (v) search an element
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int info;
    struct node *right ,*left;
};
typedef struct node node;

node* createNode(int val)
{
   
    node *newnode=(node*)malloc(sizeof(node));
    newnode->info=val;
    newnode->right=NULL;
    newnode->left=NULL;
    return newnode;
}

node* insertion(node *root,int val)
{
    if(root==NULL)
    return createNode(val);
    else
    {
        if(val < (root->info))
          root->left=insertion(root->left,val);
        else if(val > (root->info))
          root->right=insertion(root->right,val);
    }
    return root;
}
void PreorderTraversal(node *root)
{
    if(root==NULL)
    return;
    printf("%d ",root->info);
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

void InorderTraversal(node *root)
{
    if(root!=NULL)
    {
    //return;
    InorderTraversal(root->left);
    printf("%d ",root->info);
    InorderTraversal(root->right);
    }
}

void PostorderTraversal(node *root)
{
    if(root==NULL)
    return;
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    printf("%d ",root->info);
}
//search an element
bool search(node *root,int no)
{
    if (root == NULL)
      return false;

   else if(no == root->info )
      return true;
    else if(no < root->info)
      search(root->left,no);
    else if(no > root->info)
      search(root->right,no);
}
//find Maximum of element in BST
node* findMaxElement(node *root)
{
while(root!=NULL && root->right!=NULL)
{
    root=root->right;
}
return root;
}
//find Minimum of element in BST
node* findMinElement(node *root)
{
    while(root!=NULL && root->left!=NULL)
{
    root=root->left;
}
return root;
}

//deletion of a node 
node* deletion(node *root,int delno)
{
    if(root==NULL)
      return root;
    else if(delno < root->info)
    root->left=deletion(root->left,delno);
    else if(delno > root->info)
    root->right=deletion(root->right,delno);
    else
    {
    if(root->left ==NULL)
    {
    node *temp=root->right;
    free(root);
    return temp;
    }

    else if(root->right ==NULL)
    {
    node *temp=root->left;
    free(root);
    return temp;
    }
    }
    return root;
}


int main()
{
    int no,delno;
    node *root=NULL;
    bool ans=false;
    printf("NAME : Akanksha Negi \nSec: A1 \nRoll No :04\n");
        root =insertion(root,20);
        root =insertion(root,10);
        root =insertion(root,30);
        root =insertion(root,15);
        root =insertion(root,25);
    printf("Preorder Traversal : ");
    PreorderTraversal(root);
    printf("\nInorder Traversal : ");
    InorderTraversal(root);
    printf("\nPostorder Traversal : ");
    PostorderTraversal(root);

    node *max=findMaxElement(root);
    printf("\nMaximum Element in the tree is :%d ",max->info);
    node *min=findMinElement(root);
    printf("\nMinimum Element in the tree is :%d ",min->info);

    printf("\nEnter the no you want to search in the BST \n");
    scanf("%d",&no);
    ans=search(root,no);
    if(ans)
    printf("Number found !!!\n");
    else
    printf("Number not found !!!\n");

    printf("Enter the no to be deleted from the BST :\n");
    scanf("%d",&delno);
    node *del= deletion(root,delno);
    printf("Deleted no is %d ",del->info);

    printf("After Deletion of no is BST is :\n");
     printf("Preorder Traversal : ");
    PreorderTraversal(root);
    printf("\nInorder Traversal : ");
    InorderTraversal(root);
    printf("\nPostorder Traversal : ");
    PostorderTraversal(root);
    return 0;
}