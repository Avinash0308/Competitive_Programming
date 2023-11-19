#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> heights, int heights_count){
    int ans = 0;
    vector<int> dp(heights_count);
    for(int i = heights_count-1; i>=0; i--){
        int maxy = 0;
        for(int j = i+1; j<heights_count; j++){
            if(heights[j] < heights[i]){
                maxy = max(maxy,dp[j]);
            }
        }
        dp[i] = heights[i] + maxy;
        ans = max(ans,dp[i]);
    }
    return ans;
}
int main(){
    cout<<solve({21,101,2,3,100,4,5},7) <<endl;
    return 0;
}