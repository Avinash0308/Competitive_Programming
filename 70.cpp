#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    vector<long long int> x;   
    x.push_back(1);         
    int maxy = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i] > max)
            {
                max = v[i];
            }
        }
        long long int mod = 1000000007;
        if(max > maxy){
            long long int z = x[maxy];
            for(int i = maxy+1 ; i<=max ; i++){
                z  = (z*i)%mod;
                x.push_back(z);
            }
            maxy = max;
        }       
        long long int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = (ans + (x[v[i]]) % mod) % mod;
        }
        cout<<ans<<endl;
    }

    return 0;
}