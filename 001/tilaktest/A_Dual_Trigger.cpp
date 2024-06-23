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
        int off = 0;
        int adj = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                off++;
            if (i > 0 && s[i] == '1' && s[i - 1] == '1')
                adj = 1;
        }
        if (off % 2)
        {
            cout << "NO" << endl;
        }
        else if (off == 2 && adj)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}