#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(ll i = 0; i<n; i++){
            cin>>v[i];
        }
        ll maxy = 0;
        unordered_map<ll,ll> mp;
        for(ll i = 0; i<n; i++){
            mp[v[i]]++;
            maxy = max(maxy,mp[v[i]]);
        }
        cout<<n-maxy<<endl;
    }
    return 0;
}