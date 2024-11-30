#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    ll mod = 1e9+7;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(ll i = 0; i<n; i++){
            cin>>v[i]; 
        }
        ll cnt = 0, sum = 0;
        ll prev = 0;
        for(ll i = 0; i<n; i++){
            ll val = v[i];
            for(ll j = 0; j<cnt; j++){
                val (val*2)%mod;
            }
            ll cur = (val + sum)%mod;
            if(prev >= cur){
                cout<<prev<<endl;
            }
            else{
                prev = cur;
                cout<<prev<<endl;
            }
            
        }
    }
    return 0;
}