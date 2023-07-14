#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define irep(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
const int ma = 1e5 + 5;
int bit(ll x)
{
    int ans = 0;
    while (x)
    {
        x /= 2;
        ans++;
    }
    return ans;
}
bool check(ll d, ll x)
{
    if (bit(x / d) <= bit(d)){
        return true;
    }
    return false;
}
ll solve(ll x)
{
    ll l = 1, r = sqrt(x);
    while (l < r)
    {
        ll m = (l + r) / 2;
        if (check(m, x))
            r = m;
        else
            l = m + 1;
    }
    if (!check(l, x))
        return l + 1;
    else
        return l;
}
int main(int argc, char *argv[])
{
    if (argc == 2 or argc == 3)
        freopen(argv[1], "r", stdin);
    if (argc == 3)
        freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    assert(1 <= t and t <= 1e6);
    rep(i, 1, t)
    {
        ll x, ans = 0;
        cin >> x;
        assert(1 <= x and x <= 1e12);
        ll tp = solve(x);
        cout << x - tp + 1 << endl;
    }
    return 0;
}