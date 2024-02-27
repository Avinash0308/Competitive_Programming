#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        vector<long long int> a;
        for (int i = 0; i < n; i++)
        {
            long long int v;
            cin >> v;
            a.push_back(v);
        }
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 1)
            {
                cout << "YES";
                goto end;
            }
            for (int j = i + 1; j < a.size(); j++)
            {
                if (a[j] == 1)
                {
                    cout << "YES";
                    goto end;
                }
                if(__gcd(a[i], a[j]) == 1){
                    cout<<"YES";
                    goto end;
                }
            }
        }
        cout << "NO";
    end:
        cout << endl;
        continue;
    }
}
