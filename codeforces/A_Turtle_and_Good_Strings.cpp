#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        if(s[0] == s[n-1]) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}