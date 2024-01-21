#include <bits/stdc++.h>

using namespace std;
int longSubarrWthSumDivByK(int arr[], int n, int k)
{
    // Complete the function
    vector<int> v(k, -1);
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        int mod = sum % k;
        cout<<mod<<endl;
        if (mod == 0)
            ans = i + 1;
        else if (v[mod] != -1)
            ans = max(ans, i - v[mod]);
        else
            v[mod] = i;
    }
    return ans;
}
int main(){
    int arr[] = {-1,9,0};
    cout<<longSubarrWthSumDivByK(arr,3,9);
    cout<<endl;
    cout<<(-18)%9<<endl;
    return 0;
}