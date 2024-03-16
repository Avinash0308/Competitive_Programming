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
        string s;
        cin >> s;
        ll ans = 0;
        for (ll i = 0; i < n - 2; i++)
        {
            if (s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e')
            {
                ans++;
                i++;
            }
            else if (s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p')
            {
                if (i <= n - 5 && s[i + 3] == 'i' && s[i + 4] == 'e')
                {
                    i += 4;
                }
                else
                {
                    i++;
                }
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}