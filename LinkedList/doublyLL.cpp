#include<bits/stdc++.h>
using namespace std;
class node{
    public :
    int data;
    node* next;
    node* pre;
    node(int d):data(d),next(NULL),pre(NULL){};

};



void insertHead(node* &head,node* &tail,int d){
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
    // cout<<d<<" "<<"successfully inserted"<<endl;

}
void deleteFirst(node* &head,node* &tail){
    node* temp=head;
    if(head==NULL)return;

     if(head==tail){
        // cout<<head->data<<"successfully deleted first"<<endl;
         head=NULL;
         tail=NULL;
     }
     else {
         head=head->next;
         head->pre=NULL;
        // cout<<head->data<<"successfully deleted first"<<endl;
     }
    delete temp;
}
void deleteLast(node* &head,node* &tail){
    if(head==NULL)return;
    node* temp =tail;

    if(head==tail){
        head=NULL;
        tail=NULL;
    }
    else {
        tail=tail->pre;
        tail->next=NULL;
    }
    delete temp;

}
void Delete(node* &head,node* &tail,int value){
    if(head==NULL){
        return;
    }
    else if(head->data==value){
        deleteFirst(head,tail);
        return;
    }
    else{
        node* curr=head;
        while(curr!=NULL&&curr->data!=value){
            curr=curr->next;
        }
        if(curr==NULL){
            return;
        }
        if(curr->next==NULL){
            deleteLast(head,tail);
            return;
        }
        node* temp=curr;
        curr->pre->next=curr->next;
        curr->next->pre=curr->pre;
        delete temp;
        // cout<<value<<" successfully deleted"<<endl;


    }
}

void print(node* &head){

    node* temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<"\n";
}

int main()
{
    node* head=nullptr;
    node* tail=nullptr;

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int x;
        if(s== "insert"){
        cin>>x;
        insertHead(head,tail,x);

        }
        else if(s=="delete"){
            cin>>x;
            Delete(head,tail,x);
        }else if(s=="deleteFirst"){
         deleteFirst(head,tail);

        }else if(s=="deleteLast"){
            deleteLast(head,tail);
        }

    // print(head);
    }
    // cout<<"\n";
    print(head);

    return 0;



}
