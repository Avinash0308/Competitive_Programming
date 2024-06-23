#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, x, y;
        cin >> n >> x >> y;
        vector<long long int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        map<pair<int, int>, int> mp;
        for (int i = 0; i < n; i++)
        {
            int mody = v[i] % x;
            int mod2_req = v[i] % y;
            mp[{mody, mod2_req}]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int mody = v[i] % x;
            int mod_req = (x - mody) % x;
            int mod2_req = v[i] % y;
            mp[{mody, mod2_req}]--;
            if (mp.count({mod_req, mod2_req}) != 0)
            {
                ans += mp[{mod_req, mod2_req}];
            }
        }
        cout << ans << endl;
    }
    return 0;
}