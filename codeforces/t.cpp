#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    ll maxy = 1e7+1;
    vector<ll> pre(maxy,-1);
    pre[0] = 0, pre[1] = 1;

    ll val = 0;
    for(ll i = 2; i<maxy; i++){
        if(pre[i] == -1){
            val++;
            if(i==2)val = 0;
            if(i == 3) val = 2;
            for(ll j = i; j<maxy; j+=i){
                if(pre[j] == -1){
                    pre[j] = val;
                }
            }
        }
    }
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(ll i = 0; i<n; i++){
            cin>>v[i];
        }
        
    }
    return 0;
}