#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(int bag, int ind, vector<int> &arr,  int cur, int &maxy, int &miny, int &k, int &n){
    if(bag == k && ind == n){
        maxy = max(maxy,cur);
        miny = min(miny,cur);
        return;
    }
    cur += arr[ind];
    for(int i = ind; i<n-k-bag-1; i++){
        cur += arr[i];
        solve(bag+1,i+1,arr,cur,maxy,miny,k,n);
        cur -= arr[i];
    }
    cur -= arr[ind];
}
int main(){
    int k;
    int n;
    vector<int> arr(n);
    int cur;
    int maxy , miny;
    solve(0,0,arr,cur,maxy,miny,k,n);
    int ans = maxy - miny;
    return ans;
return 0;
}