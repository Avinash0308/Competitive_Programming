#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, m;
        cin>>n>>m;
        unordered_map<ll,vector<ll>> mp;
        for(ll i = 0; i<m; i++){
            ll u,v;
            cin>>u>>v;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
    }
    return 0;
}