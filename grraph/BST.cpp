#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
     }
};
node* buildTree(node* root){
    cout<<"Enter data:"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting to the left of:"<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting to the right of:"<<data<<endl;
    root->right=buildTree(root->right);
    return root;

}
void levelOrderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    while(!q.empty()){
        node* temp=q.front();
    cout<<temp->data<<" ";
        q.pop();
    if(temp->left)q.push(temp->left);
    if(temp->right)q.push(temp->right);

    }
    cout<<endl;
}
void inOrder(node* root){
    if(root==nullptr){
        return ;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void preOrder(node* root){
    if(root==nullptr){
        return ;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(node* root){
    if(root==nullptr){
        return ;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
int main(){
    node* root =NULL;
  root= buildTree(root);
  cout<<"levelorder traversal is:"<<endl;

   levelOrderTraversal(root);
   cout<<"inOrder Traversal is:"<<endl;
   inOrder(root);
   cout<<endl;
   cout<<"PreOrder traversal is:"<<endl;
   preOrder(root);
   cout<<endl;
   cout<<"Postorder traversal is:"<<endl;
   postOrder(root);
    return 0;
}
