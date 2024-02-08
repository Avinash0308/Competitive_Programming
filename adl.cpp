#include<bits/stdc++.h>
using namespace std;
long long getMaximumSum(int no_adjacent[], int one_adjacent[], int both_adjacent[], int n) {
  // Initialize dp table
  long long dp[n + 1][2];
  dp[0][0] = one_adjacent[0];
  dp[0][1] = no_adjacent[0];

  // Iterate for remaining processors
  for (int i = 1; i < n; ++i) {
    dp[i][0] = max(dp[i - 1][0] + one_adjacent[i], dp[i - 1][1] + both_adjacent[i]);
    dp[i][1] = dp[i - 1][0] + no_adjacent[i];
  }

  // Return the maximum efficiency
  return max(dp[n-1][0], dp[n-1][1]);
}
int main(){
    int a[] = {1,6};
    int b[] = {2,3};
    int c[] = {3,2};
    int ans = getMaximumSum(a,b,c,2);
    cout<<ans<<endl;
}