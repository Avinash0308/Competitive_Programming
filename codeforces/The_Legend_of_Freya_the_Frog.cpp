#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x, y, k;
        cin>>x>>y>>k;
        ll one = (x+k-1)/k;
        ll two = (y+k-1)/k;
        if(one<=two){
            cout<<two*2<<endl;
        }
        else{
            cout<<(one*2)-1<<endl;
        }
    }
    return 0;
}