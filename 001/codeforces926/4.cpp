#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int mod = 998244353;
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        vector<vector<long long int>> v(n-1);
        for(long long int i = 0; i<n-1; i++){
            long long int a, b;
            cin>>a>>b;
            v[i] = {a,b};
        }
        
    }
return 0;
}