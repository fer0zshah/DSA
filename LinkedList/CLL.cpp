#include<bits/stdc++.h>
using namespace std ;
class node{
    public:
        int data;
        node* next=NULL;
        node(int d){
            data=d;
            next=NULL;
        }
};
void insrt(node* &tail,int element,int d){

    if(tail==NULL){
        node* newnode=new node(d);
        tail=newnode;
        newnode->next=newnode;
    }else{
        node* temp=tail;
        while(temp->data!=element){
            temp=temp->next;
        }
        node* newnode=new node(d);
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void print(node* &tail){
    node* temp=tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
    cout<<endl;
}
int main()
{
    node* tail=NULL;
    insrt(tail,5,4);
    print(tail);
     insrt(tail,4,5);
   print(tail);
    return 0;
}
