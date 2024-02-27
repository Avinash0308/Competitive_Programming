#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        vector<long long int> a;
        for (int i = 0; i < n; i++)
        {
            long long int v;
            cin >> v;
            a.push_back(v);
        }
        long long int m = a[0];
        for (int i = 1; i < a.size(); i++)
        {
            if (__gcd(a[i], m) == 1)
            {
                cout << "YES";
                goto end;
            }
            m = __gcd(a[i], m);
        }
        cout << "NO";
    end:
        cout << endl;
        continue;
    }
}
