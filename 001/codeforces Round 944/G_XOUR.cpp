#include <bits/stdc++.h>
using namespace std;
#define ll long long int

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
            cin >> v[i];
        unordered_map<ll, set<ll>> mp;
        for (ll i = 0; i < n; i++)
        {
            mp[v[i]].insert(i);
        }
        for (ll i = 0; i < n; i++)
        {
            bool pos = true;
            while (pos)
            {
                if ((mp.count(v[i] - 3) != 0) && ((v[i] ^ (v[i] - 3)) < 4) && (*(mp[v[i] - 3].rbegin()) > i))
                {
                    ll ind = *(mp[v[i] - 3].rbegin());
                    mp[v[i] - 3].erase(ind);
                    mp[v[i] - 3].insert(i);
                    mp[v[i]].erase(i);
                    mp[v[i]].insert(ind);
                    v[ind] = v[i];
                    v[i] = v[i]-3;
                }
                else if ((mp.count(v[i] - 2) != 0) && ((v[i] ^ (v[i] - 2)) < 4) && (*(mp[v[i] - 2].rbegin()) > i))
                {
                    ll ind = *(mp[v[i] - 2].rbegin());
                    mp[v[i] - 2].erase(ind);
                    mp[v[i] - 2].insert(i);
                    mp[v[i]].erase(i);
                    mp[v[i]].insert(ind);
                    v[ind] = v[i];
                    v[i] = v[i]-2;
                }
                else if ((mp.count(v[i] - 1) != 0) && ((v[i] ^ (v[i] - 1)) < 4) && (*(mp[v[i] - 1].rbegin()) > i))
                {
                    ll ind = *(mp[v[i] - 1].rbegin());
                    mp[v[i] - 1].erase(ind);
                    mp[v[i] - 1].insert(i);
                    mp[v[i]].erase(i);
                    mp[v[i]].insert(ind);
                    v[ind] = v[i];
                    v[i] = v[i] - 1;
                }
                else
                {
                    pos = false;
                }
            }
        }
        for (ll i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}