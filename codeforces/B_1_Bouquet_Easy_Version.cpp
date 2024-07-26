#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, m;
        cin>>n>>m;
        vector<ll> v(n);
        for(ll i = 0; i<n; i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        ll start = -1, best = 0, ind = 0;
        ll cur = 0;
        for(ll i = 0; i<n; i++){
            cur += v[i];
            while(cur > m || v[start+1]+1 < v[i]){
                cur -= v[start+1];
                start++;
            }
            best = max(best,cur);
        }
        cout<<best<<endl;
    }
    return 0;
}