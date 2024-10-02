#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(ll ind,unordered_map<ll,vector<vector<ll>>> &e, vector<ll> &dist, unordered_map<ll,ll> &mp){
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> pq;
    pq.push({0,ind,0});
    while(!pq.empty()){
        ll i = pq.top()[1];
        ll dis = pq.top()[0];
        ll h = pq.top()[2];
        pq.pop();
        if(mp[i]) h = 1;
        if(dist[i] < dis) continue;
        dist[i] = dis;
        cout<<i<<" "<<dis<<endl;
        for(auto j:e[i]){
            ll x = j[0], w = j[1];
            if(dist[x] > (dis + (w/(h+1)))){
                pq.push({(dis + (w/(h+1))),x,h});
            }
        }
    }
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, m,h;
        cin>>n>>m>>h;
        unordered_map<ll,ll> mp;
        for(ll i = 0; i<h; i++){
            ll ho;
            cin>>ho;
            mp[ho]++;
        }
        unordered_map<ll,vector<vector<ll>>> e;
        for(ll i = 0; i<m; i++){
            ll a, b,c;
            cin>>a>>b>>c;
            e[a].push_back({b,c});
            e[b].push_back({a,c});
        }
        vector<ll> dist1(n+1,LLONG_MAX);
        vector<ll> dist2(n+1,LLONG_MAX);
        solve(1,e,dist1,mp);
        solve(n,e,dist2,mp);
        ll ans = LLONG_MAX;
        for(ll i = 1; i<=n; i++){
            if(max(dist1[i],dist2[i]) < ans){
                ans = max(dist1[i],dist2[i]);
            }
        }
        cout<<((ans == LLONG_MAX)?-1:ans)<<endl;
    }
    return 0;
}