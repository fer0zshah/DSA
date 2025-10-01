#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string arr;
    cin >> arr;
    int n = arr.size();
    char ch = *max_element(arr.begin(), arr.end());
    int k = ch - 'a';
    // cout << k << endl;
    vector<int> count(k+1, 0);


    for (int i = 0; i <n; i++)
    {
        count[arr[i] - 'a']++;
    }

    // for (int i = 0; i < k+1; i++)
    // {
    //     cout <<char(i+97)<<"->"<< count[i] <<endl;
    // }

    for (int i = 1; i < k + 1; i++)
    {
        count[i] += count[i - 1];
    }

    //  for (int i = 0; i < k+1; i++)
    // {
    //     cout << count[i] << " ";
    // }
    string ans=arr;
    for(int i=n-1;i>=0;i--){
    ans[count[arr[i]-'a']-1]=arr[i];
    count[arr[i]-'a']--;
}
    cout<<ans<<endl;
    return 0;
}