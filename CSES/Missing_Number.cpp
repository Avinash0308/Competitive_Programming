#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    ll ans = 0;
    for(ll i = 0; i<t-1; i++){
        ll val;
        cin>>val;
        ans += (i+1-val);
    }
    ans += t;
    cout<<ans<<endl;
    return 0;
}