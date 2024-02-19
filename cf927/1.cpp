#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> v(2*n);
        for(int i = 0; i<2*n; i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        long long int ans = 0;
        for(int i = 0; i<2*n; i+=2){
            ans += v[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}