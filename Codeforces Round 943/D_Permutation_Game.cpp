#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k, pb, ps;
        cin>>n>>k>>pb>>ps;
        vector<ll> v(n+1);
        for(ll i = 1; i<n+1; i++){
            cin>>v[i];
        }
        vector<ll> x(n+1);
        for(ll i = 1; i<n+1; i++){
            cin>>x[i];
        }
        ll maxy = *max_element(x.begin(),x.end());
        vector<ll> pos_b;
        unordered_map<ll,ll> visit;
        while(1){
            pos_b.push_back(pb);
            if(x[pb] == maxy || visit.count(pb) != 0) break;
            visit[pb] = 1;
            pb = v[pb];
        }
        vector<ll> pos_s;
        unordered_map<ll,ll> visit2;
        while(1){
            pos_s.push_back(ps);
            if(x[ps] == maxy || visit2.count(ps) != 0) break;
            visit2[ps] = 1;
            ps = v[ps];
        }
        ll nn = pos_b.size();
        ll nnn = pos_s.size();
        ll siz1 = min(k,nn);
        ll siz2 = min(k,nnn);
        vector<ll> a(siz1);
        vector<ll> b(siz2);
        for(ll i = siz1-1; i>=0; i--){
            ll first = (k-i)*x[pos_b[i]];
            ll second = 0;
            if(i < siz1-1){
                second = x[pos_b[i]] + a[i+1];
            }
            a[i] = max(first,second);
        }
        for(ll i = siz2-1; i>=0; i--){
            ll first = (k-i)*x[pos_s[i]];
            ll second = 0;
            if(i < siz2-1){
                second = x[pos_s[i]] + b[i+1];
            }
            b[i] = max(first,second);
        }
        if(a[0] > b[0]){
            cout<<"Bodya"<<endl;
        }
        else if(a[0] < b[0]){
            cout<<"Sasha"<<endl;
        }
        else{
            cout<<"Draw"<<endl;
        }
    }
    return 0;
}