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
        vector<pair<ll,ll>> a, b;
        for(ll i =1; i<n-1; i++){
            if(i%2){
                a.push_back({a[i],i});
            }
            else b.push_back(a[i],i);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        vector<ll> c(n);
        ll cur = n;
        for(auto i:a){
            c[i.second] = i.first + cur;
            cur--;
        }
        c[n-1] = cur;
        cur--;
        for(auto i:b){
            c[i.second] = 
        }
    }
    return 0;
}