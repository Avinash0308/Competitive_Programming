#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int a, b, x, y, k;
        cin >> a >> b >> x >> y;
        y = abs(y - b);
        x = abs(x - a);
        if ((x == 0 && y == 0))
        {
            cout << "0" << endl;
            goto there;
        }

        if (x == 0)
        {
            cout << y - 1 << endl;
            goto there;
        }
        if (y == 0)
        {
            cout << x - 1 << endl;
            goto there;
        }

        else
        {

            cout << __gcd(x, y) - 1 << endl;
        }
    there:
        continue;
    }
}
