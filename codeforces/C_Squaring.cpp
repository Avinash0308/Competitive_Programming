#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define double long double
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<double> v(n);
        for(ll i = 0; i<n; i++){
            cin>>v[i];
            v[i] = log10(v[i]);
        }
        unordered_map<double,pair<ll,double>> mp;
        ll ans = 0;
        ll pos = 1;
        for(ll i = 1; i<n && pos; i++){
            if(v[i] == 1 && v[i-1] > 1){
                pos = 0;
            }
            else if(v[i] >= v[i-1]) continue;
            else{
                ll count;
                double value;
                double ele = v[i];
                if(mp.count(v[i]) != 0){
                    count = mp[v[i]].first, value = mp[v[i]].second;
                    ans += count;
                }
                else{
                    count = 0, value = v[i];
                }
                while(v[i-1] > value){
                    value = value * value;
                    count++;
                    ans++;
                }
                v[i] = value;
                mp[ele] = {count,v[i]};
            }
        }
        if(pos) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}