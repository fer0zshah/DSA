#include<bits/stdc++.h>
using namespace std;
class node{
    public :
    int data;
    node* next;
    node* pre;
    node(int d):data(d),next(NULL),pre(NULL){};

};
void pushLeft(node* &head,node* &tail,int d){
    node* newnode=new node(d);
    if(head==NULL){
        head=newnode;
        tail=newnode;
          //  node* newnode->next=head;
    }else{
            newnode->next=head;
            head->pre=newnode;
            head=newnode;
    }

}
void pushRight(node* &head,node* &tail,int d){
    node* newnode=new node(d);
    if(tail==NULL){
        tail=newnode;
        head=newnode;
    }else{
        tail->next=newnode;
        newnode->pre=tail;
        tail=newnode;
    }
}
void popLeft(node* &head,node* &tail){
    node* temp=head;

     cout<<"Popped from left: "<<temp->data<<endl;
     if(head==tail){
         head=NULL;
         tail=NULL;
     }
     else {
         head=head->next;
         head->pre=NULL;
     }

}
void popRight(node* &head,node* &tail){
    node* temp =tail;

    if(head==tail){
        head=NULL;
        tail=NULL;
    }
    else {
        tail=tail->pre;
        tail->next=NULL;
    }

}
int main()
{
    int t;cin>>t;
    for(int i=0;i<t;i++){
       cout<<"Case "<<i+1<<":\n";


    int n,m,c=0,a;
    string s;
    cin>>n>>m;
    node* head=nullptr;
    node* tail=nullptr;
    while(m--){
       cin>>s;
       if(s=="pushLeft"){
            cin>>a;
            if(c==n){
               cout<<"The queue is full"<<endl;
            }
            else {
                pushLeft(head,tail,a);
                c++;
                cout<<"Pushed in left: "<<a<<endl;
            }

       }else if(s=="pushRight"){
           cin>>a;
             if(c==n){
               cout<<"The queue is full"<<endl;
            }
            else {
                pushRight(head,tail,a);
                c++;
                cout<<"Pushed in right: "<<a<<endl;
            }

       }else if(s=="popLeft"){
           if(c>0){
            popLeft(head,tail);

            c--;
           }else cout<<"The queue is empty"<<endl;

       }else if(s=="popRight"){
         if(c>0){
            popRight(head,tail);

                c--;
            }else{
                cout<<"The queue is empty"<<endl;
            }
         }
       }

    }

    }

