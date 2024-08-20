#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        vector<ll> v(n);
        for(ll i = 0; i<n; i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        ll a = 0, b = 0;
        for(int i = n-1; i>=0; i-=2){
            a += v[i];
            if(i-1 >= 0){
                ll x = min(k,v[i]-v[i-1]);
                b += v[i-1] + x;
                k -= x;
                v[i-1] += x;
                k = max(k,0ll);
            }
        }
        cout<<a-b<<endl;
    }
    return 0;
}