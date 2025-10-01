//#include<bits/stdc++>
#include<iostream>
using namespace std;
class node{
public:
    char data;
    node* next;
    node(char d):data(d),next(NULL){}
};
template<class T>
class Stack{
    public :
    node* head=NULL;
    void push(T d){
            node* newnode=new node(d);
        if(head==NULL){
            head=newnode;
        }else{
            newnode->next=head;
            head=newnode;
        }
    }
    void pop(){
        node* temp =head;
        head=head->next;
        temp->next=NULL;
        delete temp;

    }
    T top(){
        return head->data;
    }
    bool Empty(){
        if(head==NULL){
            return true ;
        }else{
          return  false;
        }
    }

};

bool isValid(string &s) {
       int l=s.size();
       Stack<char> st;
       for(int i=0;i<l;i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.Empty()) return false;
                if(s[i]==']'){
                    if(st.top()!='['){
                        return false;
                    }
                    else st.pop();
                }
                else if(s[i]=='}'){
                    if(st.top()!='{'){
                        return false;
                    }
                    else st.pop();
                }else if(s[i]==')'){
                    if(st.top()!='('){
                        return false;
                    }
                    else st.pop();
                }
            }
       }
       if(!st.Empty()) return false;
       return true;


    }

    int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
      string s;
      getline(cin,s);
      if(isValid(s)){
        cout<<"Yes\n";
      }
      else {
        cout<<"No\n";
      }
    }
    }
