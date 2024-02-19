#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<long long int> v;
int main()
{
    v.push_back(0);
    int t;
    cin >> t;

    while (t--)
    {
        long long int n;
        cin >> n;
        if (v.size() <= n)
        {
            long long int siz = v.size();
            for (long long int i = siz; i <= n; i++)
            {

                long long int ans = 0;
                long long int val = i;
                while (val)
                {
                    ans += (val % 10);
                    val /= 10;
                }
                v.push_back(v[i - 1] + ans);
            }
        }
        cout << v[n] << endl;
    }
    return 0;
}