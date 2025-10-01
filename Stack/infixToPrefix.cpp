#include<bits/stdc++.h>
using namespace std;
int precedence(char ch){
    if(ch=='^'){
        return 3;
    }
    else if(ch=='-'||ch=='+'){
        return 1;
    }else if(ch=='*'||ch=='/'||ch=='%'){
        return 2;
    }else{
        return -1;
    }

}
string InfixToPrefix(string &s){
    stack<char>st;
    string res;
    int l=s.size();
    for(int i=0;i<l;i++){

        if(s[i]!='+'&&s[i]!='-'&&s[i]!='/'&&s[i]!='*'&&s[i]!='^' &&s[i]!='%'&&s[i]!='('&&s[i]!=')'){
                res+=s[i];
           }
        else if(s[i]==')'){
                        st.push(s[i]);
                        }
        else if(s[i]=='('){
            while(!st.empty()&&st.top()!=')'){
                    res+=st.top();
                    st.pop();
                  }
            if(!st.empty())st.pop();
        }
        else{
                while(!st.empty()&&precedence(st.top())>precedence(s[i])){
                    res+=st.top();
                    st.pop();
                }
          st.push(s[i]);
        }

        }
         while(!st.empty()){
            res+=st.top();
            st.pop();
         }
         reverse(res.begin(),res.end());
        return res;
    }
int main()
{
    string s;

    cin>>s;

    reverse(s.begin(),s.end());
    cout<<InfixToPrefix(s)<<endl;
    return 0;
}
