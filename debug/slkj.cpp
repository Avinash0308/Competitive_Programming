#include <bits/stdc++.h>
using namespace std;

long long int findMaxProduct(vector<int> &arr)
{
    // Write your code here
    long long int n = arr.size(), ans = INT_MIN, mod = 1e9 + 7, least_neg = INT_MIN, neg_count = 0, zero = 0, pos = 1, neg = 1, ele;
    for (long long int i = 0; i < n; i++)
    {
        ele = arr[i];
        if (ele == 0)
        {
            zero++;
            continue;
        }
        if (ele < 0)
        {
            neg_count++;
            least_neg = max(least_neg, ele);
            neg = (neg * ele) % mod;
        }
        else
        {
            pos = (pos * ele) % mod;
        }
    }
    if (neg_count + zero == n)
    {
        if (neg_count <= 1)
            return 0;
        else if (neg > 0)
            return neg;
        else
            return neg / least_neg;
    }
    else
    {
        if (neg > 0)
            return (pos * neg) % mod;
        else if (neg <= 1)
            return pos;
        else
            return ((neg / least_neg) * pos) % mod;
    }
}

int main()
{
    long long int x = -5, mod = 1e9 + 7;
    vector<int> arr = {-5,-5,-5,5};
    cout<<findMaxProduct(arr)<<endl;
    return 0;
}