#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin>>a;
        vector<int> v(a);
        for(int i = 0; i<a; i++){
            cin>>v[i];
        }
        long long int ans = 0;
        for(int i = 0; i<a; i++){
            ans += abs(v[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}