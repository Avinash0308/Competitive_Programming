#include<bits/stdc++.h>
using namespace std;
int gainMaxValue(vector<int> security_val, int k){
    int n = security_val.size();
    long long int ans = INT_MIN;
    long long int cur = 0;
    for(int i = n-1; i>=0; i-=k){
        cur += security_val[i];
        ans = max(ans,cur);
    }
    return ans;
}
int main(){
    cout<<gainMaxValue({3,5,2,-4,9,16},2);
    return 0;
}