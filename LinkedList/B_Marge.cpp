#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
node* Merge(node* l1,node* l2){
    node* head=new node(0);
    node* curr=head;
    while(l1!=NULL&&l2!=NULL){
        if(l1->data<=l2->data){
            curr->next=l1;
            l1=l1->next;
        }else{
            curr->next=l2;
            l2=l2->next;
        }
        curr=curr->next;
    }
    if(l1!=NULL)curr->next=l1;
    else curr->next=l2;
    return head->next;

}
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
int main()
{
    vector<int>List1={1,2,4};
  node* node1=new node(List1[0]);
  node* head1 =node1;
  node* tail1=node1;
  int s1=List1.size();
  for(int i=1;i<s1;i++){
    tailinsert(tail1,List1[i]);
  }
  cout<<"List1:"<<endl;
  show(head1);

      vector<int>List2={1,3,4};
  node* node2=new node(List2[0]);
  node* head2 =node2;
  node* tail2=node2;
  int s2=List2.size();
  for(int i=1;i<s2;i++){
    tailinsert(tail2,List2[i]);
  }
  cout<<"List2:"<<endl;
  show(head2);
  cout<<"after merging :"<<endl;
node* head=  Merge(head1,head2);
show(head);


}
