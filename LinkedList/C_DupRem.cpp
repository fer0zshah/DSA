#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node* next=NULL;

    node(int data)
    {
        this->data=data;
        this->next=NULL;
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
void Remove(node* head){
    node* temp=head;
    while(temp->next!=NULL){
        if(temp->data==temp->next->data){
                node* nodetodelete=temp->next;
            temp->next=temp->next->next;
            nodetodelete->next=NULL;
            delete nodetodelete;
        }else{
            temp=temp->next;
        }
    }
}
void tailinsert(node* &tail,int d)
{
    node* temp=new node(d);
    tail->next=temp;
    tail=tail->next;
}
int main()
{
        vector<int>v= {1,1,2,3,3};
    int s=v.size();
    node* node1=new node(v[0]);
    node* head=node1;
    node* tail=node1;
    for( int i=1; i<s; i++)
    {
        tailinsert(tail,v[i]);
    }
    cout<<"Before Removing :"<<endl;
    show(head);
    cout<<"After Remove:"<<endl;
    Remove(head);
    show(head);


}
