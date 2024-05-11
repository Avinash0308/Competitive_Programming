#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll find_close(vector<ll> &a, ll val){
    ll n = a.size();
    ll low = 0, high = n-1;
    while(low<=high){
        ll mid = low + ((high-low)/2);
        if(a[mid] > val) high = mid-1;
        else low = mid+1;
    }
    return high;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k, q;
        cin>>n>>k>>q;
        vector<ll> a(k+1);
        for(ll i = 0; i<k; i++){
            cin>>a[i+1];
        }
        vector<ll> b(k+1);
        for(ll i = 0; i<k; i++){
            cin>>b[i+1];
        }
        vector<ll> dis(q);
        for(ll i = 0; i<q; i++){
            cin>>dis[i];
        }
        for(ll i = 0; i<q; i++){
            ll close = find_close(a,dis[i]);
            ll cur = b[close];
            ll dist = dis[i] - a[close];
            if(dist == 0) cout<<cur<<" ";
            else{
                ll diff = a[close+1]-a[close];
                ll diff2 = b[close+1]-b[close];
                ll travel = (dist*diff2)/diff;
                cur += travel;
                cout<<cur<<" ";
            }
        }
        cout<<endl;
    }   
    return 0;
}