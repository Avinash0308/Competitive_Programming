#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, w, z, i;
        w = 0;
        z = 0;
        cin >> x;
        for (int i = 1; i <= x; i++)
        {
            if (x % i == 0)
            {
                // cout<<i<<endl;
                if (i % 2 == 0)
                {
                    w++;
                }
                else
                    z++;
            }
        }

        if (w > z)
        {
            cout << 1 << endl;
        }
        else if (w == z)
        {
            cout << 0 << endl;
        }
        else if (w < z)
        {
            cout << -1 << endl;
        }
    }
}