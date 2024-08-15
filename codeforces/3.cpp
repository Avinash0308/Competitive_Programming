#include<bits/stdc++.h>
using namespace std;
#define ll double


int main(){
    ll n;
    cin>>n;
    vector<ll> a(n), b(n);
    for(ll i = 0; i<n; i++){
        cin>>a[i];
    }
    for(ll i= 0; i<n; i++){
        cin>>b[i];
    }
    ll ans = 0, val = 94;
    for(ll i = 1; i<n; i++){
        ll amt = a[i]/val;
        ans += (b[i]-b[i-1])/amt;
    }
    ans /= (n-1);
    cout<<ans<<endl;
    return 0;
}