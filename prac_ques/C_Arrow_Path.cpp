#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<string> s(2);
        cin >> s[0] >> s[1];
        vector<vector<ll>> v(2, vector<ll>(n, 0));
        queue<pair<ll, ll>> q;
        q.push({0, 0});
        while (!q.empty())
        {
            pair<ll, ll> p = q.front();
            ll j = p.first, i = p.second;
            q.pop();
            if (v[j][i] == 0)
            {
                v[j][i] = 1;
                if (i < n - 2 && s[j][i + 1] == '>')
                {
                    q.push({j, i + 2});
                }
                if (s[(j + 1) % 2][i] == '>' && i < n - 1)
                {
                    q.push({(j + 1) % 2, i + 1});
                }
                if (s[(j + 1) % 2][i] == '<' && i > 1)
                {
                    q.push({(j + 1) % 2, i - 1});
                }
                if (i >= 2 && s[j][i - 1] == '<')
                {
                    q.push({j, i - 2});
                }
            }
        }
        if (v[1][n - 1])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}