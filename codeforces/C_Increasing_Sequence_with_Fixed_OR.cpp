#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> ans;
        ans.push_back(n);
        int ind = 0;
        ll val = 1;
        while((ind<62) && (n > val)){
            if(val&n){
                ans.push_back(n-val);
            }
            val <<= 1;
            ind++;
        }
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(auto i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}