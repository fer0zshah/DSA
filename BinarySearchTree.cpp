#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    Node* root;
    Node* left;
    Node* right;
    int data;
    Node(int d){
        data=d;
        root=NULL;
        left=NULL;
        right=NULL;

    }
};
Node* insertIntoBST(Node* &root,int d){
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertIntoBST(root->right,d);
    }else{
        root->left=insertIntoBST(root->left,d);
    }
    return root ;
}

void takeinput(Node* &root)
{
    int data;
    cin>>data;
    while(data!=-1){
            insertIntoBST(root,data);
        cin>>data;

    }
}
void inOrder(Node* root){ //LNR
    if(root==NULL){
        return ;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}
void PreOrder(Node* root){ //NLR
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);

    PreOrder(root->right);

}
void PostOrder(Node* root){ //LRN
    if(root==NULL){
        return ;
    }

    PostOrder(root->left);

    PostOrder(root->right);
      cout<<root->data<<" ";

}
void Travers(Node* &root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left){
                q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }cout<<endl;

}
int main()
{
    Node* root=NULL;
   cout<<"Enter data to creat BST:"<<endl;
   takeinput(root);
   cout<<"BST Traversal is:"<<endl;
   Travers(root);
   cout<<endl;
   cout<<"Inorder Traversal is:"<<endl;
   inOrder(root);
   cout<<endl;
   cout<<"PreOrder Traversal is:"<<endl;
   PreOrder(root);
   cout<<endl;
   cout<<"PostOrder Traversal is:"<<endl;

   PostOrder(root);
   return 0;


}
