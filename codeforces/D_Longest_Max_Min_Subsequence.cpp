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
        unordered_map<ll,ll> mp;
        for(ll i = 0; i<n; i++){
            cin>>v[i];
            mp[v[i]] = i;
        }
        set<ll> s;
        vector<ll> ans;
        int len = 0;
        ll last = -1;
        unordered_map<ll,ll> visit;
        for(ll i = 0; i<n; i++){
            if(visit[v[i]]) continue;
            s.insert(v[i]);
            if(mp[v[i]] == i){
                while(!s.empty()){
                    ll value;
                    if(len%2){
                        value = *(s.begin());
                        if(value >= v[i]) break;
                        else{
                            visit[value] = 1;
                            s.erase(s.begin());
                            ans.push_back(value);
                            len++;
                        }
                    }
                    else{
                        value = *(s.rbegin());
                        if(value <= v[i]) break;
                        else{
                            visit[value] = 1;
                            s.erase(value);
                            ans.push_back(value);
                            len++;
                        }
                    }
                }
                ans.push_back(v[i]);
                visit[v[i]] = 1;
                s.erase(v[i]);
                s.clear();
                len++;
            }
        }
        cout<<len<<endl;
        for(ll i = 0; i<len; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}