#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void update1(vector<ll> &st, ll a, ll b, ll i, ll diff, ll c)
{
    if (i < a || i > b)
        return;
    st[c] = st[c] + diff;
    if (b != a)
    {
        ll m = a + ((b - a) / 2);
        update1(st, a, m, i, diff, 2 * c + 1);
        update1(st, m + 1, b, i, diff, 2 * c + 2);
    }
}
void update(vector<ll> &arr, vector<ll> &st, ll n, ll i, ll x)
{
    if (i < 0 || i > n - 1)
    {
        return;
    }
    ll diff = x - arr[i];
    arr[i] = x;
    update1(st, 0, n - 1, i, diff, 0);
}
ll find1(vector<ll> &st, ll a, ll b, ll c, ll d, ll e)
{
    if (c <= a && d >= b)
        return st[e];
    if (b < c || a > d)
        return 0;
    ll mid = a + ((b - a) / 2);
    return find1(st, a, mid, c, d, 2 * e + 1) + find1(st, mid + 1, b, c, d, 2 * e + 2);
}
ll find(vector<ll> &st, ll n, ll a, ll b)
{
    if (a < 0 || b > n - 1 || a > b)
        return 0;

    return find1(st, 0, n - 1, a, b, 0);
}
ll solve(vector<ll> &v, vector<ll> &st, ll l, ll e, ll f)
{
    if (l == e)
    {
        st[f] = v[l];
        return v[l];
    }
    ll mid = l + ((e - l) / 2);
    st[f] = solve(v, st, l, mid, f * 2 + 1) + solve(v, st, mid + 1, e, f * 2 + 2);
    return st[f];
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
        ll z = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] == 0)
                z++;
        }
        if (z == n)
            cout << 1 << endl;
        else
        {
            vector<ll> x(2 * n + 1, 0);
            ll height = (ll)(ceil(log2(2 * n + 1)));
            ll maxy = 2 * (ll)pow(2, height) - 1;
            vector<ll> st(maxy, 0);
            solve(x, st, 0, 2 * n, 0);
            update(x, st, 2 * n + 1, n, 1);
            ll diff = 0;
            ll ans = 0;
            for (ll i = 0; i < n; i++)
            {
                if (v[i] == 1)
                    diff++;
                else
                    diff--;
                update(x, st, 2 * n + 1, diff + n, x[diff + n] + 1);
                ans += find(st, 2 * n + 1, 0, n - 1 + diff);
            }
            cout << ans << endl;
        }
    }
}
