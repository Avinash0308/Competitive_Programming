#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        vector<ll> v(n);
        for(ll i = 0; i<n; i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        unordered_map<ll,vector<ll>> mp;
        for(auto i:v){
            mp[i%k].push_back(i);
        }
        bool pos = ((v.size())%2)?false:true;
        bool can = true;
        ll ans = 0;
        for(auto i:mp){
            ll len = i.second.size();
            if(len%2){
                if(pos){
                    can = false;
                    break;
                }
                else{
                    pos = true;
                    vector<ll> forw(len), back(len);
                    for(ll j = 1; j<len; j+=2){
                        forw[j] = ((i.second[j]-i.second[j-1])/k) + ((j>1)?forw[j-2]:0);
                    }
                    for(ll j = len-2; j>0; j-=2){
                        back[j] = ((i.second[j+1]-i.second[j])/k) + ((j<(len-2))?back[j+2]:0);
                    }
                    ll ansy = INT_MAX;
                    for(ll j = 0; j<len; j+=2){
                        ll cur = 0;
                        if(j > 0) cur += forw[j-1];
                        if(j<(len-1)) cur += back[j+1];
                        ansy = min(ansy,cur);
                    }
                    ans += ansy;
                }
            }
            else{
                for(ll j = 0; j<len; j+=2){
                    ans += (i.second[j+1]-i.second[j])/k;
                }
            }
        }
        if(can) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}