#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(string &s){
    int n = s.size();
    ll ans = 0, mod = 1e9+7;
    vector<vector<ll>> front(n,vector<ll>(4,0));
    vector<vector<ll>> back(n,vector<ll>(4,0));
    ll zero = 0, one = 0;
    if(s[0] == '0') zero = 1;
    else one = 1;
    for(ll i = 1; i<n; i++){
        front[i] = front[i-1];
        if(s[i] == '0'){
            front[i][0] = (front[i-1][0] + zero)%mod;
            front[i][2] = (front[i-1][2] + one)%mod;
            zero++;
        }
        else{
            front[i][1] = (front[i-1][1] + zero)%mod;
            front[i][3] = (front[i-1][3] + one)%mod;
            one++;
        }
    }
    zero = 0, one = 0;
    if(s[n-1] == '0') zero = 1;
    else one = 1;
    for(ll i = n-2; i>=0; i--){
        back[i] = back[i+1];
        if(s[i] == '0'){
            back[i][0] = (back[i+1][0] + zero)%mod;
            back[i][1] = (back[i+1][1] + one)%mod;
            zero++;
        }
        else{
            back[i][2] = (back[i+1][2] + zero)%mod;
            back[i][3] = (back[i+1][3] + one)%mod;
            one++;
        }
    }
    for(ll i = 1; i<n-1; i++){
        ll a = (front[i-1][0]*back[i+1][0])%mod;
        ll b = (front[i-1][1]*back[i+1][2])%mod;
        ll c = (front[i-1][2]*back[i+1][1])%mod;
        ll d = (front[i-1][3]*back[i+1][3])%mod;
        ans = (ans+a+b+c+d)%mod;
    }
    return ans;
}


int main(){
    string s = "0100110";
    cout<<solve(s)<<endl;
    return 0;
}