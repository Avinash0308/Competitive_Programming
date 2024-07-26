#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        vector<vector<char>> v(n,vector<char>(n));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cin>>v[i][j];
            }
        }
        for(int i = 0; i<n; i+=k){
            for(int j = 0; j<n; j+=k){
                cout<<v[i][j];
            }
        }
    }
    return 0;
}