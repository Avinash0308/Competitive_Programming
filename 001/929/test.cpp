#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int a, b, l;
        cin >> a >> b >> l;
        un
        for (long long int k = 1; k <= l; k++)
        {
            long long int cur1 = 1;
            for (long long int x = 0; (k * cur1) <= l; x++)
            {
                long long int cur2 = 1;
                for (long long int y = 0; (k * cur1 * cur2) <= l; y++)
                {
                    if ((k * cur1 * cur2) == l){
                        ans++;
                        cout<<k<<" "<<cur1<<" "<<cur2<<endl;
                    }
                    cur2 *= b;
                }
                cur1 *= a;
            }
        }
        cout << ans << endl;
    }
    return 0;
}