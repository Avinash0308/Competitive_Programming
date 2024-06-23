#include<bits/stdc++.h>
using namespace std;
long long int solve(int val, int n, int m, int x, map<pair<int,int>,long long int> &dp, int row, int k){
    if(n >= row) return 1;
    if(dp.count({row,val})) return dp[{row,val}];
    int low = max(1,val-x), high = min(val+x,k);
    long long int ans = 0;
    long long int mod = 1e9+7;
    for(int ind = low; ind<=high; ind++){
        int num = ind - low + 1;
        long long int first = pow(num,m);
        first %= mod;
        long long int second = (num == 1)?0: pow(num-1,m);
        second %= mod;
        long long int final = first-second;
        long long int cur = solve(ind,n,m,x,dp,row+1,k);
        final = (final*cur)%mod;
        ans = (ans + final)%mod;
    }
    return dp[{row,val}] = ans;
}
long long int hugeFuzzyGrid(int n, int m, int k, int x){
    map<pair<int,int>,long long int> dp;
    long long int ans = 0;
    long long int mod = 1e9+7;
    for(int i = 1; i<=k; i++){
        ans = (ans + solve(i,n,m,x,dp,0,k))%mod;
    }
    return ans;
}
int main(){
     int n, m, k, x;
     cin>>n>>m>>k>>x;
     cout<<hugeFuzzyGrid(n,m,k,x)<<endl;
     return 0;
}