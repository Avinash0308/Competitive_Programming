#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll n = s.size();
        vector<vector<ll>> v(n, vector<ll>(n, 0));
        for (ll i = n - 1; i >= 0; i--)
        {
            for (ll j = n - 1; j > i; j--)
            {
                if (s[i] != '?' && s[j] != '?' && s[i] != s[j])
                    continue;
                v[i][j] = 1;
                if (i + 1 < j && j + 1 < n)
                    v[i][j] += v[i + 1][j + 1];
            }
        }
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                if (i + v[i][j] - 1 == j - 1)
                    ans = max(ans, v[i][j] * 2);
            }
        }
        cout << ans << endl;
    }
    return 0;
}