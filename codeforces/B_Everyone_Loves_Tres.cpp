#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n%2 == 0){
            for(ll i=  0; i<n-2; i++){
                cout<<3;
            }
            cout<<66<<endl;
        }
        else{
            if(n > 3){
                for(ll i = 0; i<n-4; i++){
                    cout<<3;
                }
                cout<<6366<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
    }
    return 0;
}