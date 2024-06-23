#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        ll ans = -1;
        ll res = -1;
        for(ll i = x-1; i>=1; i--){
            ll val = __gcd(x,i);
            if(ans < val + i){
                res = i;
                ans = val + i;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}