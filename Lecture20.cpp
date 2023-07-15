#include<iostream>
#include<queue>
using namespace std;
class Node{
public:
int data;
Node* left;
Node* right;
Node(int d)
{
    data=d;
    left=NULL;
    right=NULL;
}
};
Node* insertNode(Node* root,int data)
{
if(root==NULL){
    root=new Node(data);
    return root;
}
if(root->data>data){
    root->left=insertNode(root->left,data);
}
if(root->data<data){
   root->right= insertNode(root->right,data);
}
return root;
}

Node* BST(Node* &root){
 int d;
 cin>>d;
 while(d!=-1)
 {
     root=insertNode(root,d);
     cin>>d;
 }
 return root;
}
bool search(Node* root,int find){
while(root!=NULL){
    if(root->data==find){
        return true;
    }
    if(root->data<find){
        return search(root->right,find) ;
    }
    if(root->data>find){
        return search(root->left,find) ;
    }
    return false;
}
}

void inorder(Node* root)
{
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data;
     inorder(root->right);
}



int main()
{
Node* root=NULL;
root=BST(root);
inorder(root);
cout<<endl<<search(root,50);
    return 0;
}

