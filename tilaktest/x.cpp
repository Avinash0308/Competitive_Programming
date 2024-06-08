#include <bits/stdc++.h>
using namespace std;

long long int mod = 1e9 + 7;
int countOperations(string s)
{
    // code here
    int n = s.size();
    long long int count = 0;
    long long int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            count++;
            continue;
        }
        int b = 1;
        while (i < n - 1 && s[i + 1] == 'b')
        {
            i++;
            b++;
        }
        long long int val = 1;
        long long int cur = count;
        while (cur--)
        {
            val = (val * 2) % mod;
        }
        val--;
        ans = (ans + (val * b) % mod) % mod;
    }
    return ans;
}

int main()
{   
    cout<<countOperations("abba")<<endl;
    return 0;
}