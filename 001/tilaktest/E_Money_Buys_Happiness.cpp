#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll ind, ll money, ll happy, vector<vector<ll>> &v, ll m, ll x, vector<unordered_map<ll,ll>> &dp, vector<unordered_map<ll,ll>> &mp){
    if(ind == m) return 0;
    if(mp[ind].count(happy) != 0 && mp[ind][happy] >= money) return 0;
    if(dp[ind].count(money) != 0) return dp[ind][money];
    mp[ind][happy] = money;
    ll ans = solve(ind+1,money+x,happy,v,m,x,dp,mp);
    if(money >= v[ind][0]){
        ans = max(ans,solve(ind+1,money+x-v[ind][0],happy+v[ind][1],v,m,x,dp,mp) + v[ind][1]);
    }
    return dp[ind][money] = ans;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll m, x;
        cin>>m>>x;
        vector<vector<ll>> v(m);
        for(ll i = 0; i<m; i++){
            ll c, h;
            cin>>c>>h;
            v[i] = {c,h};
        }
        vector<unordered_map<ll,ll>> dp(m);
        vector<unordered_map<ll,ll>> mp(m);
        ll ans = 0;
        ll money = 0, ind = 0, happy = 0;
        cout<<solve(ind,money,0,v,m,x,dp,mp)<<endl;
    }
    return 0;
}