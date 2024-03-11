#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll one = 0;
        while(n){
            if(n%2) one++;
            n/=2;
        }
        if(one%2){
            cout<<"ODD"<<endl;
        }
        else{
            cout<<"EVEN"<<endl;
        }
    }
return 0;
}