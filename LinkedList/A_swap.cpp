#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void tailinsert(node* &tail,int d){
    node* temp=new node(d);
    tail->next=temp;
    tail=tail->next;
}
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
void headinsert(node* &head,int d){
    node* temp=new node(d) ;
    temp->next=head;
    head=temp;
}
node* Swap(node* head){

        if(head==NULL|| head->next==NULL)
        {
            return head;
        }
        node* curr=head->next->next;
        node* pre=head;
        head=head->next;
        head->next=pre;

        while(curr!=NULL&& curr->next!=NULL){
            pre->next=curr->next;
            pre=curr;
            node* temp=curr->next->next;
            curr->next->next=curr;
            curr=temp;
        }

        pre->next=curr;
        return head;
}
int main()
{
//    vector<int>v= {1,2,3,4};
//    node* node1=new node(v[0]);
//    int s=v.size();
//    node* head=node1;
//    node* tail=node1;
//    for(int i=1;i<s;i++){
//        tailinsert(tail,v[i]);
//    }
        node* node1=new node(4);
        node* head=node1;
        node* tail=node1;
        headinsert(head,3);
        headinsert(head,2);
        headinsert(head,1);
    cout<<"before swap"<<endl;
    show(head);
    cout<<"after swap:"<<endl;
    Swap(head);
    show(head);

}
