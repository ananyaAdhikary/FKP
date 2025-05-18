#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int value)
{
    struct node *temp=new node;
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node *insertion(struct node *root,int value)
{
    if(root==NULL)
        return createNode(value);
    if(value<root->data)
        root->left=insertion(root->left,value);
    else
        root->right=insertion(root->right,value);
    return root;
}
void inorderTraverse(struct node *root)
{
    if(root!=NULL)
    {
        inorderTraverse(root->left);
        cout<<root->data<<" ";
        inorderTraverse(root->right);
    }
}
int main()
{
    int n,value;
    cout<<"Enter the number of element you want to insert:";
    cin>>n;
    struct node *root;
    root=NULL;
    cout<<"enter the elements:";
    for(int i=0;i<n;i++)
        {
            cin>>value;
            root=insertion(root,value);
        }
  cout<<"the sorted elements are:";
   inorderTraverse(root);
}
