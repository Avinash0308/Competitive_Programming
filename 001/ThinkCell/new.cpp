#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll term = k;
    vector<ll> v(term,1);
    for(ll i = 2; i*i <= term; i++){
        if(v[i] != 1) continue;
        for(ll j = i*i; j <= term; j+=i){
            if(v[j] == 1){
                v[j] = i;
            }
        }
    }
    vector<ll> mp(term,0);
    for(ll i = 2; i<=term; i++){
        if(v[i] == 1) v[i] = i;
        ll diff = i/v[i];
        mp[diff] += i;
    }
    ll t;
    cin >> t;
    while (t--)
    {
        ll k;
        cin>>k;
        cout<<mp[k]<<endl;
    }
    return 0;
}