#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a, b, c, d;
        cin>>a>>b>>c>>d;
        if(a > b) swap(a,b);
        if(c > d) swap(c,d);
        int x = 0, y = 0;
        if((a < c && b > c && b < d) || (a > c && d > a && b > d)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}