#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool solve(ll mid, vector<ll> &v, ll n){
    ll value = mid;
    for(ll i = 0; i<n; i++){
        ll val = mid/v[i];
        val++;
        value -= val;
    }
    if(value >= 0) return true;
    else return false;
}
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
        ll minimum = 1, maximum = 1e9;
        ll ans = -1;
        while (minimum <= maximum)
        {
            ll mid = minimum + ((maximum - minimum) / 2);
            if (solve(mid, v, n))
            {
                ans = mid;
                break;
            }
            else
            {
                minimum = mid + 1;
            }
        }
        if (ans == -1)
            cout << -1 << endl;
        else
        {
            for (ll i = 0; i < n; i++)
            {
                ll value = ans/v[i];
                cout<<value+1<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}