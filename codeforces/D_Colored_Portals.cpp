#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, q;
        cin>>n>>q;
        vector<string> v(n);
        for(ll i = 0; i<n; i++){
            cin>>v[i];
        }
        vector<vector<ll>> query(q,vector<ll>(2));
        for(ll i = 0; i<q; i++){
            cin>>query[i][0]>>query[i][1];
        }
        vector<unordered_map<string,ll>> left(n), right(n);
        unordered_map<string,ll> l;
        for(ll i = 0; i<n; i++){
            l[v[i]] = i;
            left[i] = l;
        }
        unordered_map<string,ll> r;
        for(ll i =n-1; i>=0; i--){
            r[v[i]] = i;
            right[i] = r;
        }
        for(ll i = 0; i<q; i++){
            ll a = query[i][0]-1, b = query[i][1]-1;
            if(v[a][0] == v[b][0] || v[a][0] == v[b][1] || v[a][1] == v[b][0] || v[a][1] == v[b][1]) cout<<abs(a-b)<<endl;
            else{
                if(a > b) swap(a,b);
                vector<string> s;
                ll val = -1, val2 = n;
                for(auto j:left[b]){
                    if(j.first == v[a]) continue;
                    if(j.first == v[b]) continue;
                    val = max(val,j.second);
                }
                for(auto j:right[a]){
                    if(j.first == v[a]) continue;
                    if(j.first == v[b]) continue;
                    val2 = min(val2,j.second);
                }
                ll ans = INT_MAX;
                if(val != -1){
                    ans = abs(a-val) + abs(b-val);
                }
                if(val2 != n){
                    ans = min(ans,abs(a-val2)+abs(b-val2));
                }
                if(ans == INT_MAX) cout<<-1<<endl;
                else cout<<ans<<endl;
            }
        }
    }
    return 0;
}