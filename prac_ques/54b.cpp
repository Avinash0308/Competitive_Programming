#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), brr(n), temp1(n), temp2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        temp1[i] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> brr[i];
        temp2[i] = brr[i];
    }
    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());
    temp1.erase(unique(temp1.begin(), temp1.end()), temp1.end());
    temp2.erase(unique(temp2.begin(), temp2.end()), temp2.end());
    for (int i = 0; i < n; i++)
    {
        arr[i] = lower_bound(temp1.begin(), temp1.end(), arr[i]) - temp1.begin();
    }
    for (int i = 0; i < n; i++)
    {
        brr[i] = lower_bound(temp2.begin(), temp2.end(), brr[i]) - temp2.begin();
    }
    int temp = 0, ans = 0;
    vector<int> p(n), q(n), r, crr(n);
    for (int i = 0; i < n; i++)
    {
        crr[arr[i]] = brr[i];
        p[i] = arr[i] + brr[i];
        q[brr[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        r.insert(upper_bound(r.begin(), r.end(), crr[i]), crr[i]);
        p[q[crr[i]]] -= lower_bound(r.begin(), r.end(), crr[i]) - r.begin();
    }
    for (auto i : p)
    {
        temp = max(i, temp);
    }
    for (auto i : p)
    {
        ans += (i == temp);
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}