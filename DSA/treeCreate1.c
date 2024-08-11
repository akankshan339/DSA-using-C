//#include<stdio.h>
#include<iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
    node(int data)
    {
        this->data=data;
        this->left=left;
        this->right=right;
    }
};
node *createTree(node *root)
{
    int data
    cout<<"enter data\n";
    cin>>data;
    root=new node(data);
    if(data==-1)
    return NULL;

    root->left=createTree(root->left);
    root->right=createTree(root->right);
    return data;
}

int main()
{
    node *root=NULL;
    root=createTree(root);
    return 0;
}