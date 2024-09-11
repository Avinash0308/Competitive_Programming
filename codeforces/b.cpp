#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &v){
    int sum = accumulate(v.begin(),v.end(),0);
    int ans = 0, cur = 0;
    for(int i = 0; i<n-1; i++){
        cur += v[i];
        sum -= v[i];
        if(cur == sum) ans++;
    }
    return ans;
}

int solve2(int n, vector<int> &v, int k){
    unordered_map<int,int> a, b;
    for(int i = 0; i<n; i++){
        b[v[i]] = i;
    }
    for(int i = n-1; i>=0; i--){
        a[v[i]] = i;
    }
    unordered_map<int,int> ans;
    int sum = accumulate(v.begin(),v.end(),0);
    int cur = 0;
    for(int i = 0; i<n-1; i++){
        cur += v[i];
        sum -= v[i];
        int val = cur-sum;
        if(a.count(k+val) != 0 && a[k+val] <= i) ans[a[k+val]]++;
        if(b.count(k-val) != 0 && b[k-val] > i) ans[b[k-val]]++;
    }
    int res = 0;
    for(auto i:ans){
        res = max(res,i.second);
    }
    return res;
}

int main(){
    int n, k;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    cin>>k;
    int a = solve(n,v);
    a = max(a,solve2(n,v,k));
    cout<<a<<endl;
    return 0;
}