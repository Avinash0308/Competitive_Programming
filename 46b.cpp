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
        int a = v.size(), b = v1.size();
        int x = 0, z = 0;
        if (a > b)
        {

            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0 && x < b)
                {
                    arr[i] = v1[x];
                    x++;
                }
                else
                {
                    arr[i] = v[z];
                    z++;
                }
            }
        }
        else
        {

            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 1 && z < a)
                {
                    arr[i] = v[z];
                    z++;
                }
                else
                {
                    arr[i] = v1[x];
                    x++;
                }
            }
        }
    }
};
int main()
{

    return 0;
}