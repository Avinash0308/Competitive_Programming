#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        unordered_map<char,int> mp;
        for(int i=  0; i<n; i++){
            mp[s[i]]++;
        }
        vector<pair<int,char>> v;
        for(auto i:mp){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end());
        int len = v.size();
        int value = v[len-1].first;
        char c = v[len-1].second;
        vector<char> ans(n);
        int i = 0;
        if(value > (n+1)/2){
            while(i<n){
                ans[i] = c;
                i+=2;
                value--;
            }
            if(i == n){
                i--;
            }
            else i = n-2;
            while(value){
                ans[i] = c;
                value--;
                i-=2;
            }
            for(int j = len-2; j>=0; j--){
                value = v[j].first;
                while(value--){
                    ans[i]  = v[j].second;
                    i-=2;
                }
            }
        }
        else{
            for(int j = len-1; j>=0; j--){
                value = v[j].first;
                while(value--){
                    if(i >= n) i = 1;
                    ans[i] = v[j].second;
                    i+=2;
                }
            }
        }
        for(int i = 0; i<n; i++){
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}