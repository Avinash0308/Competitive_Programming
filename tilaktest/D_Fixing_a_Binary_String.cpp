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
        string s;
        cin >> s;
        vector<ll> v;
        for (ll i = 0; i < n; i++)
        {
            ll count = 1;
            while (i < n - 1 && s[i] == s[i + 1])
            {
                count++;
                i++;
            }
            v.push_back(count);
        }
        ll i = 0;
        ll siz = v.size();
        while (i < siz && v[i] == k)
            i++;
        if (i == siz)
        {
            cout << n << endl;
        }
        else
        {
            if (v[i] > k)
            {
                if(i == siz-1) cout<<-1<<endl;
                else if (v[i] == 2 * k)
                {
                    ll j = i + 1;
                    while (j < siz && v[j] == k)
                        j++;
                    if (j == siz)
                    {
                        if ((siz - i - 1) % 2)
                        {
                            cout << k * (i + 1) << endl;
                        }
                        else
                        {
                            cout << -1 << endl;
                        }
                    }
                    else
                    {
                        cout << -1 << endl;
                    }
                }
                else if(v[i] + v[siz-1] == 2*k)
                {
                    if((i%2) == (siz-1)%2){
                        ll j = i + 1;
                        while (j < siz - 1 && v[j] == k)
                            j++;
                        if (j == siz - 1)
                        {
                            cout << (k * i) + v[i] - k << endl;
                        }
                        else
                        {
                            cout << -1 << endl;
                        }
                    }
                    else{
                        cout<<-1<<endl;
                    }
                }

                else{
                    cout<<-1<<endl;
                }
            }
            else
            {
                if (i == siz - 1)
                    cout << -1 << endl;
                else
                {
                    if (v[i] + v[siz - 1] == k && ((i % 2) == ((siz - 1) % 2)))
                    {
                        ll j = i + 1;
                        while (j < siz - 1 && v[j] == k)
                            j++;
                        if (j == siz - 1)
                        {
                            cout << (k * i) + v[i] << endl;
                        }
                        else
                        {
                            cout << -1 << endl;
                        }
                    }
                    else
                    {
                        cout << -1 << endl;
                    }
                }
            }
        }
        /*vector<ll> front(n,1), back(n,1);
        for(ll i = k; i<n; i++){
            if(s[i] != s[i-k]){
                front[i] = front[i-k] + 1;
            }
        }
        for(ll i = n-1-k; i>=0; i--){
            if(s[i] != s[i+k]){
                back[i] = back[i+k] + 1;
            }
        }
        for(ll i = 0; i<v.size(); i++){
            if(v[i] == k) continue;
        }*/
    }
    return 0;
}