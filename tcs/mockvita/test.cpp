#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> solve(int n, vector<vector<int>> q){
    vector<vector<int>> a(n,vector<int>(2,0)), b(n,vector<int>(2,0));
    vector<vector<int>> c(n,vector<int>(2,0)), d(n,vector<int>(2,0));
    
    vector<int> ans(n,0);
    for(int i = 0; i<q.size(); i++){
        int val = q[i][1], ind = q[i][0];
        ans[ind] -= val;
        a[max(0,ind-val)][0] += max(0,val-ind);
        a[max(0,ind-val)][1] ++;
        c[ind][0] = val;
        c[ind][1]++;
        b[min(ind+val,n-1)][0] += max(0,val-n+1+ind);
        b[min(ind+val,n-1)][1] ++;
        d[ind][0] = val;
        d[ind][1]++;
    }
    int cur = 0 ,num = 0;
    for(int i = 0; i<n; i++){
        cur += num;
        cur += a[i][0];
        num += a[i][1];
        ans[i] += cur;
        cur -= c[i][0];
        num -= c[i][1];
    }
    cur = num = 0;
    for(int i = n-1; i>=0; i--){
        cur += b[i][0];
        num += b[i][1];
        ans[i] += cur;
        cur -= d[i][0];
        num -= d[i][1];
        cur += num;
    }
    return ans;
}

int main(){
    vector<int> ans = solve(5,{{2,2},{1,3},{4,1}});
    for(auto i:ans) cout<<i<<" ";
    return 0;
}