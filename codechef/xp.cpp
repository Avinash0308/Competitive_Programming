#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(ll len, ll start, ll end, vector<ll> &tree){
    ll res = 0;
    for(ll i  = start + len, j = end + len; i < j; i/=2, j/=2){
        if(i%2 == 1){
            res += tree[i];
            i++;
        }
        if(j%2 == 1){
            j--;
            res += tree[j];
        }
    }
    return res;
}

void solve2(ll len, ll index, vector<ll> &tree){
    tree[len + index]++;
    for(ll i = len + index; i>1; i/=2){
        tree[i/2] = tree[i] + tree[i^1];
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        ll z = 0;
        for(ll i = 0; i<n; i++){
            cin>>v[i];
            if(v[i] == 0) z++;
        }
        if(z == n) cout<<0<<endl;
        else{
            ll len = 2*n + 2;
            vector<ll> tree(2*len,0);
            solve2(len,n,tree);
            ll diff = 0;
            ll ans = 0;
            for(ll i = 0; i<n; i++){
                if(v[i] == 1) diff++;
                else diff--;
                solve2(len,diff+n,tree);
                ans += solve(len,1,n+diff,tree);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}