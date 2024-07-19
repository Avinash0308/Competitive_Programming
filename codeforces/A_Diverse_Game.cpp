#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, m;
        cin>>n>>m;
        vector<vector<ll>> v(n,vector<ll> (m));
        for(ll i = 0; i<n; i++){
            for(ll j = 0; j<m; j++){
                cin>>v[i][j];
            }
        }
        if(n == 1 && m == 1) cout<<-1<<endl;
        else if(m > 1){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m-1; j++){
                    swap(v[i][j],v[i][j+1]);
                }
            }
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m;j ++){
                    cout<<v[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        else{
            for(int i = 0; i<n-1; i++){
                cout<<v[i+1][0]<<" ";
            }
            cout<<v[0][0]<<endl;
        }
    }
    return 0;
}