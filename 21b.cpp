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
            if ((x % 2 == 1 && y % 2 == 0) || (x % 2 == 0 && y % 2 == 1))
            {
                cout << "0" << endl;
                goto there;
            }
            else
            {
                if (x > y)
                {
                    int temp = x;
                    x = y;
                    y = temp;
                }
                int i = 1;
                while (i <= x)
                {
                    if (x % i == 0)
                    {
                        k = x / i;
                        if (y % k == 0)
                        {
                            cout << k - 1 << endl;
                            goto there;
                        }
                    }
                    i++;
                }
            }
        }
    there:
        continue;
    }
}
