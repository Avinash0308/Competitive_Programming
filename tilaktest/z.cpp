#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, int> mp;
    mp[0] = 1;
    mp[2] = 2;
    mp[1] = 3;
    unordered_map<int, int> zp;
    zp[2] = 2;
    zp[1] = 3;
    zp[0] = 1;
    if (mp == zp)
        cout << "Chal Gaya" << endl;
    else
        cout << "Phas Gaya" << endl;
    return 0;
}