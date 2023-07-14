#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, ans = 0;
        cin >> n;
        int i = 1;
        while (i <= sqrt(n))
        {
            i = i * 2;
            if (n / i >= i / 2)
            {
                ans = n - n / i;
            }
            else
            {
                ans = (n - (i / 2)) + 1;
            }
        }

        cout << ans << "\n";
    }
}