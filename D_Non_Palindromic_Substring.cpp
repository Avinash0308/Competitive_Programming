#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<pair<ll, ll>> query(q);
        for (ll i = 0; i < q; i++)
        {
            ll a, b;
            cin >> a >> b;
            query[i] = {a, b};
        }
        
    }
    return 0;
}