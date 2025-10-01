#include<iostream>
using namespace std;
class node{
public:
    char data;
    node* next;
    node* prev;
    node(int d):data(d),next(NULL),prev(NULL){}
};

int main()
{
    int l;
    cin>>l;
    string s;
    cin>>s;

    node* node1=new node(0);
    node* head=node1;
    node* curr=node1;

    for(int i=1;i<l;i++){
        if(s[i]=='L'){
            node* newnode=new node(i);
            newnode->next=curr;
            curr->prev->next=newnode;
            newnode->prev=curr->prev;
            curr=newnode;
            if(s[i-1]!='R'){
                head=curr;
            }

        }else{
            node* newnode=new node(i);
            curr->next=newnode;
            newnode->prev=curr;
            newnode->next=curr->next->next;
            curr=newnode;
        }
    }
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;

}
