#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll rating = v[k - 1];
        k--;

        ll ind = -1;
        while (ind + 1 < k && v[ind + 1] < rating)
            ind++;
        if (ind == k - 1)
        {
            ll win = k;
            ind = k + 1;
            while (ind < n && v[ind] < rating)
            {
                ind++;
                win++;
            }
            cout << win << endl;
        }
        else
        {
            ll win = ind;
            ll count = (ind == -1)?0:1;
            ind += 2;
            while (ind < k && v[ind] < rating)
            {
                ind++;
                count++;
            }
            cout << max(count, win) << endl;
        }
    }
    return 0;
}