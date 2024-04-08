#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        vector<ll> p(4);
        for(ll i = 0; i<4; i++) cin>>p[i];
        ll ans = 0;
        ans += (p[3]/2);
        if(p[0]%2 == 1 && p[1]%2 == 1 && p[2]%2 == 1) ans++;
        ans += (p[0]/2);
        ans += (p[1]/2);
        ans += (p[2]/2);
        cout<<ans<<endl;
    }
    return 0;
}