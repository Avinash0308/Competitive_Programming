#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        unordered_map<ll,ll> v;
        ll total = 0;
        for(ll i = 1; i<=n; i++){
            ll a;
            cin>>a;
            v[i] = a;
            total += a;
        }
        vector<vector<ll>> dir(n+1);
        for(ll i =0; i<n-1; i++){
            ll a, b;
            cin>>a>>b;
            dir[a].push_back(b);
            dir[b].push_back(a);
        }
        vector<vector<ll>> lvl;
        vector<ll> add;
        vector<ll> visit(n+1);
        queue<ll> q;
        q.push(1);
        while(!q.empty()){
            vector<ll> cur;
            ll sum = 0;
            ll len = q.size();
            while(len--){
                ll ind = q.front();
                q.pop();
                if(visit[ind]) continue;
                visit[ind] = 1;
                cur.push_back(ind);
                sum += v[ind];
                for(auto i:dir[ind]){
                    q.push(i);
                }
            }
            lvl.push_back(cur);
            add.push_back(sum);
        }
        ll len = lvl.size();
        vector<ll> ans(len);
        ll res = total;
        for(int i = len-1; i>=0; i--){
            if(i+3 < len){
                ll val1 = add[i] + ans[i+2];
                ll val2 = add[i] + ans[i+3] - min(add[i+1],add[i+2]);
            }
            else if(i+2 < len){
                ans[i] = add[i] + ans[i+2];
            }
            else{
                ans[i] = add[i];
            }
        }
    }
    return 0;
}