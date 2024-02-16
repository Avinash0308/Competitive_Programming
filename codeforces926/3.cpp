#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int k, x, a;
        cin >> k >> x >> a;
        if ((x >= a) || (((a - x) * k) <= a))
        {
            cout << "NO" << endl;
        }
        else
        {
            long long int some = (a / k) + 1;
            long long int cur = a;
            int pos = 1;
            for (long long int i = 0; i < x && pos; i++)
            {
                long long int val = ((a - cur) / (k-1)) + 1;
                cur -= val;
                if (cur < some)
                {
                    pos = 0;
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