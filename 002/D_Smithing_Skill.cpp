#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n, m;
    cin>>n>>m;
    vector<pair<ll,ll>> a(n);
    vector<ll> c(m);
    for(ll i =0; i<n; i++){
        cin>>a[i].second;
    }
    for(ll i = 0; i<n; i++){
        cin>>a[i].first;
    }
    for(ll i = 0; i<m; i++){
        cin>>c[i];
    }
    for(ll i = 0; i<n; i++){
        a[i].first = a[i].second - a[i].first;
    }
    sort(a.begin(),a.end());
    vector<pair<ll,ll>> b;
    b.push_back(a[0]);
    ll last = a[0].second;
    for(ll i = 1; i<n; i++){
        if(a[i].second < last){
            b.push_back(a[i]);
            last = a[i].second;
        }
    }
    priority_queue<ll> y;
    ll exp = 0;
    for(ll i =0; i<m; i++){
        y.push(c[i]);
    }
    for(auto i:b){
        ll diff = i.first;
        ll start = i.second;
        while(!y.empty() && start <= y.top()){
            ll val = y.top()-start;
            ll tot = (val/diff) + 1;
            exp += tot*2;
            val = y.top() - (diff*tot);
            y.pop();
            if(val >= b.back().second) y.push(val);
        }
    }
    cout<<exp<<endl;
    return 0;
}