#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, m;
        cin>>n>>m;
        string a, b;
        cin>>a>>b;
        ll cur = 0;
        ll i = 0, j = 0;
        while(i<n && j < m){
            if(a[i] == b[j]){
                i++;
                j++;
                cur++;
            }
            else{
                j++;
            }
        }
        cout<<cur<<endl;
    }
    return 0;
}