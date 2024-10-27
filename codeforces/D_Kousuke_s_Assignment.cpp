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
        for(ll i=  0; i<n; i++){
            cin>>v[i];
        }
        ll last = -1, cnt = 0;
        unordered_map<ll,ll> mp;
        mp[0] = -1;
        ll sum = 0;
        for(ll i = 0; i<n; i++){
            sum += v[i];
            if(mp.count(sum) != 0){
                if(mp[sum] >= last){
                    cnt++;
                    last = i;
                }
            }
            mp[sum] = i;
        }
        cout<<cnt<<endl;
    }
    return 0;
}