#include <bits/stdc++.h>
using namespace std;
#define ll long long int

typedef pair<ll, ll> pii;

pii solve(ll n, vector<ll> &a, vector<ll> &b, ll mid, ll k)
{
    ll ans = 0, op = 0;
    for (ll i = 0; i < n; i++)
    {
        ll value = a[i], ded = b[i];
        if (value < mid)
            continue;
        ll divi = ((value - mid) / ded) + 1;
        op += divi;
        divi = min(divi,k);
        ll last = (value - ((divi - 1) * ded));
        ans += ((divi*(value+last))/2);
        k -= divi;
    }
    return {op,ans};
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        ll maxy = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            maxy = max(maxy, a[i]);
        }
        vector<ll> b(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        ll low = 0, high = maxy;
        ll ans = 0;
        while (low <= high)
        {
            ll mid = low + ((high - low) / 2);
            pii ret = solve(n, a, b, mid,k);
            ans = max(ans, ret.second);
            if (ret.first > k)
                low = mid + 1;
            
            else
            {
                high = mid - 1;
            }
        }
        pii first = solve(n,a,b,low,k);
        pii second = solve(n,a,b,high,k);
        ans = max(ans,first.second);
        ans = max(ans,second.second);
        cout << ans << endl;
    }
    return 0;
}