#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, k;
        cin >> n >> k;
        if (k <= ((n - 1) * 4))
        {
            cout << (k + 1) / 2 << endl;
        }
        else if(k == ((4*n)-2))
        {
            cout<<n*2<<endl;
        }
        else{
            cout<<(n*2)-1<<endl;
        }
    }
    return 0;
}