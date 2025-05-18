#include<bits/stdc++.h>
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
void sorting(struct node *root,int arr[],int &i)
{
    if(root!=NULL)
    {
        sorting(root->left,arr,i);
        arr[i++]=root->data;
        sorting(root->right,arr,i);
    }
}
void BSTsort(int arr[],int n)
{
    struct node *root=NULL;
    for(int i=0;i<n;i++)
    {
        root=insertion(root,arr[i]);
    }
    int index=0;
    sorting(root,arr,index);
}

int main()
{
    int n;
    cout<<"Enter the number of element you want to enter in the array:";
    cin>>n;
    int arr[n+1];
    cout<<"Enter the array elements:";
     for(int i=0;i<n;i++)
       cin>>arr[i];

    cout<<"The original array is:";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    BSTsort(arr,n);
    cout<<"The sorted array is:";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
