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
        vector<long long int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        long long int smallest = 1e9;
        for (int i = 0; i < n; i++)
        {
            smallest = min(smallest, v[i]);
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == smallest)
                count++;
        }
        if (count == 1)
            cout << "YES" << endl;
        else
        {
            int pos = 0;
            for (int i = 0; i < n; i++)
            {
                if (v[i] % smallest)
                {
                    pos = 1;
                    break;
                }
            }
            if (pos)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}