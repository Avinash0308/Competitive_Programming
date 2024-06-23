#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string b;
        cin>>b;
        string s;
        vector<int> v(26);
        for(auto i:b){
            v[i-'a']++;
        }
        for(int i = 0; i<26; i++){
            if(v[i]){
                s.push_back(char(i+97));
            }
        }
        int i = 0, j = s.size()-1;
        unordered_map<char,char> mp;
        while(i<=j){
            mp[s[i]] = s[j];
            mp[s[j]] = s[i];
            i++;
            j--;
        }
        string ans;
        for(auto z:b){
            ans.push_back(mp[z]);
        }
        cout<<ans<<endl;
    }
    return 0;
}