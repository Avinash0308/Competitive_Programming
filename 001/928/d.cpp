#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        unordered_map<long long int,long long int> mp;
        for (long long int i = 0; i < n; i++)
        {
            long long int val;
            cin >> val;
            mp[val]++;
        }
        long long int val_m = 2147483647;
        long long int ans = 0;
        for (auto value : mp)
        {
            if(value.second == 0) continue;
            long long int oth = val_m - value.first;
            long long int num = 0;
            if (mp.count(oth) != 0)
            {
                num = mp[oth];
                mp[oth] = 0;
            }
            long long int maxy = max(num, value.second);
            ans += maxy;
        }
        cout << ans << endl;
    }
    return 0;
}