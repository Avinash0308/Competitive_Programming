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
        for(ll i= 0; i<n; i++){
            cin>>v[i];
        }
        ll cur = INT_MAX;
        ll ind = 0;
        ll last = 0;
        while(ind<n){
            if(v[0] != v[ind]){
                cur = min(cur,ind-last);
                last = ind+1;
            }
            ind++;
        }
        cur = min(cur,n-last);
        if(cur == n) cout<<-1<<endl;
        else cout<<cur<<endl;
    }
    return 0;
}