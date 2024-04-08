#include<bits/stdc++.h>
using namespace std;

int minMax(int N, vector<int> A){
    unordered_map<int,int> mp;
    int ans = INT_MIN;
    sort(A.begin(),A.end());
    for(int i = 0; i<N; i++){
        int val = A[i];
        while(mp.count(val/2) == 0 && val > 1){
            val/=2;
        }
        mp[val] = 1;
        ans = max(ans,val);
    }
    return ans;
}

int main(){
    return 0;
}