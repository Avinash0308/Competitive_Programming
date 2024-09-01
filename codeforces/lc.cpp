#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll ans = 0;
bool comp(vector<int> a, vector<int> b)
{
    double first = (double)a[0] / a[1];
    double second = (double)b[0] / b[1];
    if (first > second)
        return true;
    else if (first < second)
        return false;
    else
        return a[0] >= b[0];
}
long long minDamage(int power, vector<int> &damage, vector<int> &health)
{
    vector<vector<int>> v;
    ll n = damage.size();
    for (ll i = 0; i < n; i++)
    {
        v.push_back({damage[i], health[i]});
    }
    sort(v.begin(), v.end(), comp);
    ll ans = 0, t = 0;
    for (ll i = 0; i < n; i++)
    {
        ll d = v[i][0], h = v[i][1];
        cout<<d<<" "<<h<<endl;
        ll div = (h + power - 1) / power;
        t += div;
        ans += t * d;
    }
    return ans;
}

int main()
{
    vector<int> d = {1,2,3,4};
    vector<int> h = {4,5,6,8};
    cout<<minDamage(4,d,h)<<endl;
    return 0;
}