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
        ll ans = 0;
        ll val = 1;
        for(ll i = 0; i<31; i++){
            ll cur = 0;
            ll th = 0;
            for(ll j = 0; j<n; j++){
                if(v[j]&val) cur = 0;
                else cur++;
                th = max(th,cur);
            }
            if(th != n) ans = max(ans,th);
            val <<= 1;
        }
        cout<<ans+1<<endl;
    }
    return 0;
}