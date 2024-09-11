#include<bits/stdc++.h>
using namespace std;


int getMinDiff(vector<int> &arr, int n, int k)
{
    sort(arr.begin(),arr.end());
    int ans = arr[n - 1] - arr[0];
 
    int tempmin, tempmax;
    tempmin = arr[0];
    tempmax = arr[n - 1];
 
    for (int i = 1; i < n; i++) {
        if (arr[i] - k < 0)
            continue;
        tempmin = min(arr[0] + k, arr[i] - k);
        tempmax = max(arr[i - 1] + k, arr[n - 1] - k);
 
        ans = min(ans, tempmax - tempmin);
    }
    return ans;
}

int main(){
    int n, k;
    cin>>k>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    cout<<getMinDiff(v,n,k)<<endl;
    return 0;
}
