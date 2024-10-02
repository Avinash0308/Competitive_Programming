#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(vector<ll> &v){
    ll n = v.size();
    vector<ll> x;
    for(ll i = 0; i<n; i++){
        ll sum = v[i];
        ll ind = i;
        while(i<n-1 && ((sum + i-ind)/(i-ind+1)) >= v[i+1]){
            sum += v[i+1];
            i++;
        }
        if((sum % (i-ind+1)) == 0){
            x.push_back(sum/(i-ind+1));
        }
        else{
            x.push_back(sum/(i-ind+1));
            x.push_back((sum/(i-ind+1)) + 1);
        }
    }
    if(x.size() == v.size()){
        return x[n-1] - x[0];
    }
    else return solve(x);
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(ll i = 0; i<n; i++){
            cin>>v[i];
        }
        cout<<solve(v)<<endl;
    }
    return 0;
}