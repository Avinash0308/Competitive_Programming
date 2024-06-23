#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> maximizeArray(int arr1[], int arr2[], int n)
    {
        // code here
        unordered_map<int, int> m;
        unordered_map<int, int> p;
        m[arr1[0]] = 0;
        p[arr2[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            if (m.find(arr1[i]) == m.end())
            {
                m[arr1[i]] = i;
            }
            if (p.find(arr2[i]) == p.end())
            {
                p[arr2[i]] = i;
            }
        }
        vector<int> v;
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + n);
        int i = n - 1;
        int j = n - 1;
        int k = 0;
        while (k < n && i >= 0 && j >= 0)
        {
            while (arr1[i] == arr1[i - 1] && i >= 1)
            {
                i--;
            }
            while (arr2[j] == arr2[j - 1] && j >= 1)
            {
                j--;
            }
            if (arr1[i] == arr2[j])
            {
                v.push_back(arr1[j]);
                i--;
                j--;
            }
            else if (arr1[i] > arr2[j])
            {
                v.push_back(arr1[i]);
                i--;
            }
            else
            {
                v.push_back(arr2[j]);
                j--;
            }
            k++;
        }
        while (k < n && i >= 0)
        {
            v.push_back(arr1[i]);
            i--;
            k++;
        }
        while (k < n && j >= 0)
        {
            v.push_back(arr2[j]);
            j--;
            k++;
        }
        vector<int> x(2 * n, -1);
        for (int i = 0; i < n; i++)
        {
            if (p.find(v[i]) != p.end())
            {
                x[p[v[i]]] = v[i];
            }
            else
            {
                x[m[v[i]] + n] = v[i];
            }
        }
        vector<int> res;
        for (int i = 0; i < 2 * n; i++)
        {
            if (x[i] != -1)
            {
                res.push_back(x[i]);
            }
        }
        return res;
    }
};
int main()
{

    return 0;
}