#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    if(t == 1) cout<<1<<endl;
    else if(t<=3) cout<<"NO SOLUTION"<<endl;
    else{
        for(ll i = 2; i<=t; i+=2){
            cout<<i<<" ";
        }
        for(ll i = 1; i<=t; i+=2){
            cout<<i<<" "; 
        }
        cout<<endl;
    }
    return 0;
}