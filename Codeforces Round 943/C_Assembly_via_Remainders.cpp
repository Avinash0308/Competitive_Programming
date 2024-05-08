#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n-1);
        for(ll i = 0; i<n-1; i++){
            cin>>v[i];
        }
        vector<ll> ans(n);
        ll maxy = *max_element(v.begin(),v.end());
        ans[0] = maxy + 1;
        for(int i = 1; i<n; i++){
            ans[i] = ans[i-1] + v[i-1];
        }
        for(ll i = 0; i<n; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}