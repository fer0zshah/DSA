#include<bits/stdc++.h>
using namespace std;
class node{
public:
    node* next=NULL;
    int data;
    node(int data){
       this->data=data;
       this->next=NULL;

    }

};
void headinsert(node* &head,int d){

    if(head==NULL){
      node* temp=new node(d) ;
        head=temp;
    }
    node* temp=new node(d);
    temp->next=head;
    head=temp;
}
bool check_cycle(node* &head){
    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast->next!=NULL){
        fast=fast->next;
    }
    if(slow->data==fast->data){

        return true ;
    }

        return false;

}
void print(node* &head){
    node* temp=head;
    while(temp->next!=NULL){
            cout<<temp->data<<" ";
       temp=temp->next;
    }
    cout<<endl;
}

int main()
{
//    node* node1=new node(10);
//    node* head=node1;
   node* head=NULL;
   headinsert(head,10);
   print(head);
     headinsert(head,12);
    print(head);
}
