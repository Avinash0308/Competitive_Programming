#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll r;
        cin >> r;
        ll maxy = (r+1)*(r+1);
        ll miny = r*r;
        ll count = 0;
        for(ll i = 0; i<=r; i++){
            ll first = maxy - (i*i);
            ll second = miny - (i*i);
            ll val1 = sqrt(first);
            if(val1 * val1 == first) val1--;
            ll val2 = sqrt(second);
            if(val2 * val2 < second) val2++;
            count += (val1-val2+1);
        }
        count = (count-1)*4;
        cout<<count<<endl;
    }
    return 0;
}