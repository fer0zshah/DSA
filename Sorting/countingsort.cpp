#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
 
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,k;
cin>>n>>k;
vector<int>arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}

vector<int>count(k+1,0);
for(int i=0;i<n;i++){
        count[arr[i]]++;
}
// for(int i=0;i<k+1;i++){
//        cout<<i<<"->"<< count[i]<<endl;
// }cout<<endl;
for(int i=1;i<k+1;i++){
    count[i]+=count[i-1];
}
// for(int i=0;i<8;i++){
//        cout<< count[i]<<" ";
// }
vector<int>ans(n);
for(int i=n-1;i>=0;i--){
    ans[count[arr[i]]-1]=arr[i];
    count[arr[i]]--;
}
// cout<<endl;
for(int i=0;i<n;i++){
       cout<< ans[i]<<" ";
}

 return 0;
}