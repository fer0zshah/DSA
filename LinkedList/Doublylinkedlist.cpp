#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node* next=NULL;
    node* prev=NULL;

    node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    ~node()
    {
        int value=this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"memory free for the node:"<<value<<endl;
    }


};
void show(node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<< " ";
        temp=temp->next;
    }
    cout<<endl;

}
int getLenght(node* &head){
 node* temp=head;
 int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    cout<<endl;

    return count;
}
void headinsert(node* &head,int d){
    if(head==NULL){
        node* temp=new node(d);
        head=temp;
    }else{
    node* temp=new node(d);
    temp->next=head;
    head->pre=temp;
    head=temp;}

}
void tailinsert(node* &tail,int d){
    if(tail==NULL){
        node* tail=new node(d);
        tail=temp;
    }else{
    node* temp=new node(d);
    tail->next=temp;
    temp->pre=tail;
    tail=temp;
    }
}
void anypos(node* &head,node* &tail,int pos,int d){
    node* temp=head;
    int count=1;
    if(pos==1){
        headinsert(head,d);
            return;
    }

    while(count<pos-1){
     temp=temp->next;
     count++;
    }
    if(temp->next==NULL){
        tailinsert(tail,d);
    return;
    }
    node* newnode=new node(d);
    newnode->next=temp->next;
    temp->next->pre=newnode;
    temp->next=newnode;
    newnode->pre=temp;

}

void nodedelete(node* &head,int pos){
    node* temp=head;
     if(pos==1){
        temp->next->pre=NULL;
        head=temp->next;

        temp->next=NULL;
        delete temp;
     }
     node* curr;
     node* pre;
     int count=0;
     while(count<=pos){

     }
}

int main()
{

    node* head=NULL;
    tail* tail=NULL;



}
