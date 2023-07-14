#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n)
    {
        // Your code goes here
        int max = *max_element(arr2, arr2 + n);
        int min = *min_element(arr2, arr2 + n);

        sort(arr2, arr2 + n);
        vector<int> v;
        for (int i = 0; i < m; i++)
        {
            int x = 0;
            if (max <= arr1[i])
            {
                x = n;
            }
            else if (min > arr1[i])
            {
                x = 0;
            }
            else
            {
                if (arr2[n / 2] <= arr1[i])
                {
                    int j = n / 2;
                    while (arr2[j] <= arr1[i])
                    {
                        j++;
                    }
                    x = j;
                }
                else if (arr2[n / 2] > arr1[i])
                {
                    int j = n / 2;
                    while (arr2[j] > arr1[i])
                    {
                        j--;
                    }
                    x = j + 1;
                }
            }
            v.push_back(x);
        }
        return v;
    }
};
int main(){
    
return 0;
}