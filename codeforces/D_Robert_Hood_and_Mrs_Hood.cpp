#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, d, k;
        cin>>n>>d>>k;;
        vector<vector<ll>> v(n+1);
        for(ll i = 1; i<=k; i++){
            ll l, r;
            cin>>l>>r;
            v[l].push_back(r);
        }
        multiset<ll> m;
        ll a = -1, b = k+1;
        ll ans1 = 1, ans2 = 1;
        for(ll i = 1; i<=n; i++){
            for(auto j:v[i]){
                m.insert(j);
            }
            while(!m.empty() && *(m.begin()) < i-d+1) m.erase(m.begin());
            if(i>=d){
                ll len = m.size();
                if(len > a){
                    a = len;
                    ans1 = i-d+1;
                }
                if(len < b){
                    b = len;
                    ans2 = i-d+1;
                }
            }
        }
        cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}