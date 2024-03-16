#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, x;
        cin >> n >> m >> x;
        vector<pair<ll, char>> v(m);
        for (ll i = 0; i < m; i++)
        {
            cin >> v[i].first >> v[i].second;
        }
        unordered_set<ll> s;
        s.insert(x);
        for (ll i = 0; i < m; i++)
        {
            char c = v[i].second;
            ll mag = v[i].first;
            unordered_set<ll> se;
            if (c == '0')
            {
                for (auto j : s)
                {
                    ll fin = j + mag;
                    fin %= n;
                    if (!fin)
                        fin = n;
                    se.insert(fin);
                }
            }
            else if (c == '?')
            {
                for (auto j : s)
                {
                    ll fin1 = j + mag;
                    fin1 %= n;
                    ll fin2;
                    if (j > mag)
                    {
                        fin2 = j - mag;
                    }
                    else
                    {
                        fin2 = n - mag + j;
                    }
                    fin2 %= n;
                    if (!fin1)
                        fin1 = n;
                    if (!fin2)
                        fin2 = n;
                    se.insert(fin1);
                    se.insert(fin2);
                }
            }
            else
            {
                for (auto j : s)
                {
                    ll fin2;
                    if (j > mag)
                    {
                        fin2 = j - mag;
                    }
                    else
                    {
                        fin2 = n - mag + j;
                    }
                    fin2 %= n;
                    if (!fin2)
                        fin2 = n;
                    se.insert(fin2);
                }
            }
            s.clear();
            s = se;
        }
        ll ans = s.size();
        vector<ll> anss;
        for (auto i : s)
        {
            anss.push_back(i);
        }
        cout << ans << endl;
        sort(anss.begin(), anss.end());
        for (auto i : anss)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}