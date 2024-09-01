#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(ll ind, ll ele, vector<ll> &cur, unordered_map<ll,ll> &vis, vector<ll> &ans, vector<ll> &v, string &s, unordered_map<ll,ll> &index){
    if(ans[v[ind]] != -1) return ans[v[ind]];
    if(vis.count(v[ind]) == 0){
        vis[v[ind]] = ele;
        if(v[ind] == ind+1){
            if(s[ind] == '0') return ans[v[ind]] = 1;
            else return ans[v[ind]] = 0;
        }
        else{
            cur.push_back(v[ind]);
            ll val = solve(v[ind]-1,ele+1,cur,vis,ans,v,s,index);
            if(ans[v[ind]] != -1) return ans[v[ind]];
            cur.pop_back();
            return ans[v[ind]] = val + (s[ind] == '0');
        }
    }
    else{
        ll cnt = 0;
        for(ll i =  vis[v[ind]]; i<ele; i++){
            if(s[index[cur[i]]] == '0') cnt++;
        }
        while(cur.back() != v[ind]){
            ans[cur.back()] = cnt;
            cur.pop_back();
        }
        ans[v[ind]] = cnt;
        cur.pop_back();
        return cnt;
    }
}

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
        string s;
        cin>>s;
        unordered_map<ll,ll> index;
        for(ll i = 0; i<n; i++){
            index[v[i]] = i;
        }
        vector<ll> ans(n+1,-1);
        for(ll i = 0 ;i<n; i++){
            if(ans[v[i]] == -1){
                unordered_map<ll,ll> vis;
                vector<ll> cur;
                solve(i,0,cur,vis,ans,v,s,index);
            }
        }
        for(ll i = 1; i<=n; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}