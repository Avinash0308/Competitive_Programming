#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, c, d;
        cin>>n>>c>>d;
        unordered_map<int,int> mp;
        vector<ll> v;
        for(int i = 0; i<n*n; i++){
            ll val;
            cin>>val;
            mp[val]++;
            v.push_back(val);
        }
        sort(v.begin(),v.end());
        mp[v[0]]--;
        vector<ll> last(n);
        last[0] = v[0];
        vector<ll> cur(n);
        cur[0] = v[0];
        int pos = 1;
        for(ll i = 0; i<n; i++){
            for(ll j = 0; j<n; j++){
                if(i == 0 && j == 0) continue;
                if(i == 0){
                    if(mp.count(cur[j-1] + d) != 0){
                        cur[j] = cur[j-1] + d;
                        mp[cur[j]]--;
                        if(mp[cur[j]] == 0){
                            mp.erase(cur[j]);
                        }
                    }
                    else{
                        pos = 0;
                        break;
                    }
                }
                else if(j == 0){
                    if(mp.count(last[j] + c) != 0){
                        cur[j] = last[j] + c;
                        mp[cur[j]]--;
                        if(mp[cur[j]] == 0){
                            mp.erase(cur[j]);
                        }
                    }
                    else{
                        pos = 0;
                        break;
                    }
                }
                else{
                    if(((last[j] + c) == (cur[j-1] + d)) && mp.count(last[j]+c) != 0){
                        cur[j] = last[j] + c;
                        mp[cur[j]]--;
                        if(mp[cur[j]] == 0){
                            mp.erase(cur[j]);
                        }
                    }
                    else{
                        pos = 0;
                        break;
                    }
                }
                last = cur;
            }
        }
        if(pos) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}