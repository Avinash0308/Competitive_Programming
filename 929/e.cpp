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
        for (int i = 1; i < n; i++)
        {
            v[i] += v[i - 1];
        }
        long long int q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            long long int l, u;
            cin >> l >> u;
            l--;
            long long int rmv = (l == 0) ? 0 : v[l - 1];
            long long int low = l, high = n - 1;
            while (low <= high)
            {
                long long int mid = low + ((high - low) / 2);
                long long int val = v[mid] - rmv;
                if (val <= u)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            low = min(n - 1, low);
            low = max(l, low);
            long long int res1 = ((v[low] - rmv) * (2 * u + 1 - v[low] + rmv)) / 2;
            long long int res2 = (low == l) ? INT_MIN : (((v[low - 1] - rmv) * (2 * u + 1 - v[low - 1] + rmv)) / 2);
            if(res1 > res2){
                cout<<low+1<<endl;
            }
            else{
                cout<<low<<endl;
            }
        }
    }
    return 0;
}