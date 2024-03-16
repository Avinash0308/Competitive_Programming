#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<int> l;
        ll prev = INT_MIN;
        ll pos = 1;
        for(int i = 0; i<n && pos; i++){
            ll val = v[i];
            if(i>0 && val < v[i-1]){
                for(int j = 1; j<l.size() && pos; j++){
                    if(l[j] < l[j-1]){
                        pos = 0;
                    }
                }
                if(pos){
                    if(val < l.back()) pos = 0;
                }
            }
            if(!val){
                l.push_back(0);
            }
            else{
                vector<ll> x;
                while(val){
                    x.push_back(val%10);
                    val/=10;
                }
                reverse(x.begin(),x.end());
                for(int j = 0; j<x.size(); j++) l.push_back(x[j]);
            }
        }
        if(pos) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}