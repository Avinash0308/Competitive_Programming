#include<bits/stdc++.h>
using namespace std;

long long int solve(int ind, long long int n, long long int m, long long int x, vector<vector<long long int>> &v){
    if(ind == n){
        if(x == 0) return 1;
        else return 0;
    }
    if(x<=0) return 0;
    if(v[ind][x] != -1) return v[ind][x];
    v[ind][x] = 0;
    for(int i = 1; i<=m; i++){
        v[ind][x] += solve(ind+1,n,m,x-i,v);
    }
    return v[ind][x];
}

int main(){
    int n , m , x;
    cin>>n>>m>>x;
    vector<vector<long long int>> v(n,vector<long long int>(x+1,-1));
    cout<<solve(0,n,m,x,v)<<endl; 
    return 0;
}