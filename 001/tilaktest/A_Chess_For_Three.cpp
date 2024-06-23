#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a, b, c;
        cin>>a>>b>>c;
        if((a+b+c)%2) cout<<-1<<endl;
        else if(a+b >= c){
            cout << (a+b+c)/2<<endl;
        }
        else{
            cout<<a+b<<endl;
        }
    }
    return 0;
}