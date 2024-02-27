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
        unordered_map<long long int, int> mp;
        long long int cur1 = 1;
        for (long long int x = 0; cur1 <= l; x++)
        {
            long long int cur2 = 1;
            for(long long int y = 0; cur1 * cur2 <= l; y++){
                if(l%(cur1*cur2) == 0){
                    mp[l/(cur1*cur2)]++;
                }
                cur2 *= b;
            }
            cur1 *= a;
        }
        int ans = mp.size();
        cout << ans << endl;
    }
    return 0;
}