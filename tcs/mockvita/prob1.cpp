#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{

    ll n, m, src1, src2, dest1, dest2, mov1, mov2;
    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    cin >> src1 >> src2 >> dest1 >> dest2 >> mov1 >> mov2;
    vector<vector<ll>> dir = {{mov1, mov2}, {mov2, -mov1}, {-mov2, mov1}, {-mov1, -mov2}};
    vector<vector<ll>> dp(n, vector<ll>(m, INT_MAX));
    if (v[dest1][dest2] == 1 || v[src1][src2] == 1)
        cout << -1 << endl;
    else
    {
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
        pq.push({0, src1, src2});
        while (!pq.empty())
        {
            vector<ll> cur = pq.top();
            pq.pop();
            ll x = cur[1], y = cur[2], dist = cur[0];
            if (x < 0 || x >= n || y < 0 || y >= m || v[x][y] == 1 || dp[x][y] <= dist)
                continue;
            dp[x][y] = dist;
            if (x == dest1 && y == dest2)
            {
                break;
            }
            for (auto i : dir)
            {
                pq.push({dist + 1, x + i[0], y + i[1]});
            }
        }
        if (dp[dest1][dest2] == INT_MAX)
            cout << -1 << endl;
        else
            cout << dp[dest1][dest2] << endl;
    }
    return 0;
}