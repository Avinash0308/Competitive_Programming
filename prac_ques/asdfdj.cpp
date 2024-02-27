#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string create(long long int a, long long int b)
{
    stringstream ss;
    ss << a;
    string s;
    ss >> s;
    s += " ";
    stringstream sss;
    sss << b;
    string str2;
    sss >> str2;
    s += str2;
    return s;
}
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
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            long long int mody = v[i] % x;
            long long int mod2_req = v[i] % y;
            string str = create(mody, mod2_req);
            mp[str]++;
        }
        long long int ans = 0;
        for (int i = 0; i < n; i++)
        {
            long long int mody = v[i] % x;
            long long int mod_req = (x - mody) % x;
            long long int mod2_req = v[i] % y;
            string str = create(mody, mod2_req);
            mp[str]--;
            string str2 = create(mod_req, mod2_req);
            if (mp.count(str2) != 0)
            {
                ans += mp[str2];
            }
        }
        cout << ans << endl;
    }
    return 0;
}