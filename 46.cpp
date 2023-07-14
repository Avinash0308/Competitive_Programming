#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rearrange(int arr[], int n)
    {
        // code here
        vector<int> v;
        vector<int> v1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                v.push_back(arr[i]);
            }
            else
            {
                v1.push_back(arr[i]);
            }
        }
        int m = v.size();
        int nn = v1.size();

        if (arr[0] < 0)
        {
            if (nn > m)
            {
                for (int i = 0; i < m; i++)
                {
                    arr[i * 2] = v[i];
                    arr[i * 2 + 1] = v1[i];
                }
                for (int i = 0; i < nn - m; i++)
                {
                    arr[2 * m + i] = v1[m + i];
                }
            }
            else
            {
                for (int i = 0; i < nn; i++)
                {
                    arr[i * 2] = v[i];
                    arr[i * 2 + 1] = v1[i];
                }
                for (int i = 0; i < m - nn; i++)
                {
                    arr[2 * m + i] = v[m + i];
                }
            }
        }
        else
        {
            if (nn > m)
            {
                for (int i = 0; i < m; i++)
                {
                    arr[i * 2] = v1[i];
                    arr[i * 2 + 1] = v[i];
                }
                for (int i = 0; i < nn - m; i++)
                {
                    arr[2 * m + i] = v1[m + i];
                }
            }
            else
            {
                for (int i = 0; i < nn; i++)
                {
                    arr[i * 2] = v1[i];
                    arr[i * 2 + 1] = v[i];
                }
                for (int i = 0; i < m - nn; i++)
                {
                    arr[2 * m + i] = v1[m + i];
                }
            }
        }
    }
};
int main()
{

    return 0;
}