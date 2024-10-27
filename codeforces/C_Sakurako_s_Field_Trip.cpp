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
        for(ll i = 0; i<n; i++){
            cin>>v[i];
        }
        vector<vector<ll>> dp(n,vector<ll>(2,0));
        ll l = (n-1)/2, r = n/2;
        while(l>=0){
            if(l == r){
            }
            else if(l+1 == r){
                if(v[l] == v[r]){
                    dp[l][0] = dp[l][1] = 1;
                }
            }
            else{
                ll cnt = 0, cnt1 = 0;
                if(v[l] == v[l+1]) cnt++;
                if(v[r] == v[r-1]) cnt++;
                if(v[l] == v[r-1]) cnt1++;
                if(v[r] == v[l+1]) cnt1++;
                dp[l][0] = min(dp[l+1][0] + cnt, dp[l+1][1] + cnt1);
                dp[l][1] = min(dp[l+1][0] + cnt1, dp[l+1][1] + cnt);
            }
            l--,r++;
        }
        cout<<min(dp[0][0],dp[0][1])<<endl;
    }
    return 0;
}