#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<vector<ll>> v(n);
        unordered_map<ll,ll> x, y;
        for(ll i = 0; i<n; i++){
            ll a, b;
            cin>>a>>b;
            v[i] = {a,b};
            x[a]++;
            y[b]++;
        }
        ll ans = 0;
        for(ll i = 0; i<n; i++){
            ans += (x[v[i][0]]-1)*(y[v[i][1]] -1);
        }
        cout<<ans<<endl;
    }
    return 0;
}