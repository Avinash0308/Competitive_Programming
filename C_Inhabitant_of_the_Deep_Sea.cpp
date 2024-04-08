#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll i = 0, j = n - 1, ans = 0;;
        while ((i<j) && k)
        {
            if(v[i] <= v[j]){
                if(k >= (2*v[i] - 1)){
                    k -= (2*v[i] - 1);
                    ans++;
                    v[j] -= (v[i]-1);
                    i++;
                    if(k){
                        k--;
                        v[j]--;
                        if(v[j] == 0){
                            j--;
                            ans++;
                        }
                    }
                }
                else{
                    k = 0;
                }
            }
            else{
                if(k >= (2*v[j])){
                    k -= (2*v[j]);
                    v[i] -= v[j];
                    ans++;
                    j--;
                }
                else{
                    k = 0;
                }
            }
        }
        if(k && (i == j)){
            if(k >= v[i] && v[i]) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}