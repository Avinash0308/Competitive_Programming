#include <bits/stdc++.h>
using namespace std;
#define ll long long int
long long minOps(long long a, long long b)
{
    // code here
    if (a == b)
        return 0;
    if (a > b)
        return -1;
    long long ans = 0;
    while (a < b)
    {
        long long val = sqrt(b);
        if (val < a)
        {
            cout<<"a "<<val<<" "<<a<<endl;
            ans += (b - a);
            b = a;
        }
        else
        {
            if ((val * val) == b)
            {
                cout<<"b "<<val<<" "<<b<<endl;
                b = val;
                ans++;
            }
            else
            {
                ans += ((b - (val * val)));
                cout<<"c "<<val*val<<" "<<b<<" "<<b-(val*val)<<endl;
                b = val * val;
            }
        }
    }
    return ans;
}
int main()
{
    cout << minOps(11,999999999999999982) << endl;
    ll val = sqrt(999999999999999999);
    cout<<val<<" "<<val*val<<endl;
    return 0;
}