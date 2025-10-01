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


//Traverse
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
//first insert
void headinsert(node* &head,int d)
{
    node* temp=new node(d) ;
    temp->next=head;
    head=temp;
}
//last insert
void tailinsert(node* &tail,int d)
{
    node* temp=new node(d);
    tail->next=temp;
    tail=tail->next;
}
void insertAfterVal(node* &head,int val,int v)
{
    node* newnode=new node(85);
    node* temp=head;
    while(temp->data!=val)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;


}
void insertBefore(node* &head,int val,int v)
{
    node* newnode=new node(80);
    node* temp=head;
    while(temp->next->data!=val)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void deleteFirst(node* &head)
{
    node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
}
void deleteLast(node* &head)
{
    node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    delete temp->next;
}
void deleteAfterVal(node* &head,int val){
    node* temp=head;
    while(temp->data!=val){
        temp=temp->next;
    }
    node* nodetodelete=temp->next;
    temp->next=temp->next->next;
    nodetodelete->next=NULL;
    delete nodetodelete;

}
 void deleteBefore(node* &head,int val){
    node* temp=head;
    node* pretemp=NULL;
    while(temp->next->data!=val){
            pretemp=temp;
        temp=temp->next;
    }
    pretemp->next=temp->next;
    temp->next=NULL;
    delete temp;
}
int main()
{
    vector<int>v= {1,4,5,6,7,9};
    int s=v.size();
    node* node1=new node(v[0]);
    node* head=node1;
    node* tail=node1;
    for( int i=1; i<s; i++)
    {
        tailinsert(tail,v[i]);
    }
    show(head);
    cout<<"insert 85 after val 5 :"<<endl;
    insertAfterVal(head,5,85);
    show(head);
    cout<<"insert 80  before val 7:"<<endl;
    insertBefore(head,7,80);
    show(head);
    cout<<"after deleting head:"<<endl;
    deleteFirst(head);
    show(head);
    cout<<"after deleting last element:"<<endl;
    deleteLast(head);
    show(head);
    cout<<"delete the node after 5:"<<endl;
    deleteAfterVal(head,5);
    show(head);
    cout<<"delete the node before 7:"<<endl;
    deleteBefore(head,7);
    show(head);
}
