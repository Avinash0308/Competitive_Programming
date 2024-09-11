#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<string> v(n);
        for(ll i = 0; i<n; i++){
            cin>>v[i];
        }
        for(ll i = n-1; i>=0; i--){
            for(int j = 0; j<4; j++){
                if(v[i][j] == '#'){
                    cout<<j+1<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}