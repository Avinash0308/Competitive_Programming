#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll y, z;
        cin>>y>>z;
        if(y >= z){
            ll value;
            if(y%2){
                value = (y-1)*(y-1) + 1;
                value += z-1;
            }
            else{
                value = y*y;
                value -= (z-1);
            }
            cout<<value<<endl;
        }
        else{
            ll value;
            if(z%2){
                value = z*z;
                value -= (y-1);
            }
            else{
                value = (z-1)*(z-1) + 1;
                value += (y-1);
            }
            cout<<value<<endl;
        }
    }
    return 0;
}