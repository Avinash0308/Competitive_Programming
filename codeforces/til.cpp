#include <bits/stdc++.h>
using namespace std;

long long int build(long long int start, long long int end, vector<long long int> &prime)
{
    prime[0] = prime[1] = 1;
    for (long long int i = 2; i * i <= end; i++)
    {
        if (prime[i])
            continue;
        for (long long int j = i * i; j <= end; j += i)
        {
            prime[j] = 1;
        }
    }
    long long int count = 0;
    for (long long int i = start; i <= end; i++)
    {
        if (prime[i - 1] == 0 && prime[i + 1] == 0)
            count++;
    }
    return count;
}

int main()
{
    long long int s, e;
    cin >> s >> e;
    vector<long long int> prime(e + 2);
    cout << build(s - 1, e + 1, prime) << endl;
    return 0;
}