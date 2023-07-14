#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long int x = -1;
        cin >> n;
        vector<long long int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        if (v[0] > v[n - 1])
        {
            cout << x << endl;
        }
        else
        {
            x = v[n - 1] - v[0];
            long long int f = x;
            for (int i = 1; i < n / 2; i++)
            {
                long long int z = v[n - i - 1] - v[i];
                if (v[i] > v[n - i - 1])
                {
                    x = -1;
                    goto end;
                }
                else
                {

                    if (z > f)
                    {
                        x = -1;
                        goto end;
                    }
                    else
                    {
                        f = z;
                    }
                }
            }
        end:
            cout << x << endl;
        }
    }
    return 0;
}