#include<bits/stdc++.h>
using namespace std;
#define ll long long int
unordered_map<ll,unordered_map<ll,ll>> mp;
ll solve(ll a, ll b){
    if(a < b) return solve(b,a);
    if((mp.count(a) != 0) && (mp[a].count(b) != 0)){
        return mp[a][b];
    }
    ll val1 = solve(a-1,b);
    if(val1 == 1){
        mp[a][b] = 0;
        return 0;
    }
    else{
        if(b > 0){
            ll val2 = solve(a,b-1);
            if(val2 == 1){
                mp[a][b] = 0;
                return 0;
            }
            else{
                mp[a][b] = 1;
                return 1;
            }
        }
        else{
            mp[a][b] = 1;
            return 1;
        }
    }
}
int main(){
    mp[1][0] = 1;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll one = 0, two = 0;
        for(auto c:s){
            if(c == '0') one++;
            else two++;
        }
        if(two > one) swap(one,two);
        ll ans = solve(one,two);
        if(ans) cout<<"BOB"<<endl;
        else cout<<"ALICE"<<endl;
    }
    return 0;
}