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
        for(ll i = 0; i<n; i++){
            cin>>v[i];
        }
        vector<vector<int>> x;
        for(int i = 0; i<n-2; i++){
            x.push_back({v[i],v[i+1],v[i+2]});
        }
        ll ans = 0;
        for(ll j = 0; j<3; j++){
            map<vector<ll>,unordered_map<ll,ll>>  mp;
            for(ll i = 0; i<n-2; i++){
                mp[{x[i][j],x[i][(j+1)%3]}][x[i][(j+2)%3]]++;
            }
            for(auto vec:mp){
                ll total = 0;
                ll some = 0;
                for(auto ele:vec.second){
                    total += ele.second;
                    some += ((ele.second-1)*(ele.second))/2;
                }
                total = ((total-1)*(total))/2;
                total -= some;
                ans += total;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}