#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define m 1000000007

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Recursive function to return (x ^ n) % m
ll modexp(ll x, ll n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return modexp((x * x) % m, n / 2);
    }
    else
    {
        return (x * modexp((x * x) % m, (n - 1) / 2) % m);
    }
}

// Function to return the fraction modulo mod
ll getFractionModulo(ll a, ll b)
{
    ll c = gcd(a, b);

    a = a / c;
    b = b / c;

    // (b ^ m-2) % m
    ll d = modexp(b, m - 2);

    // Final answer
    ll ans = ((a % m) * (d % m)) % m;

    return ans;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (ll i = n - 2; i >= 0; i--)
        {
            v[i] = (v[i+1] + v[i])%m;
        }
        ll total = 0;
        for (ll i = 0; i < n - 1; i++)
        {
            total = (total + (((v[i] - v[i + 1] + m) * v[i + 1])%m))%m;
            total %= m;
        }
        ll cnt = getFractionModulo((n*(n-1))%m, 2);
        cout << getFractionModulo(total, cnt) << endl;
    }
    return 0;
}