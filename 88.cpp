#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> maximumToys(int N, vector<int> A, int Q, vector<vector<int>> Queries)
    {
        vector<vector<int>> arr(N);
        for (int i = 0; i < N; i++)
        {
            arr[i] = {A[i], i};
        }
        sort(arr.begin(), arr.end());
        multimap<int, int> mpp;
        vector<long long> nums(N);
        long long sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i][0];
            nums[i] = sum;
            mpp.insert({arr[i][0], i});
        }

        vector<int> ans(Q);
        for (int i = 0; i < Q; i++)
        {
            vector<int> temp = Queries[i];
            int amount = temp[0];
            if (amount < nums[0])
            {
                ans[i] = 0;
                continue;
            }
            int idx = lower_bound(nums.begin(), nums.end(), amount) - nums.begin();
            if (idx == N or nums[idx] != amount)
            {
                idx--;
                amount = nums[idx];
            }
            int cnt = idx + 1;
            unordered_set<int> st;
            if (temp[1] != 0)
            {
                for (int j = 2; j < temp.size(); j++)
                {
                    --temp[j];
                    auto it = mpp.find(A[temp[j]]);
                    if (it->second > idx)
                    {
                        st.insert(temp[j]);
                    }
                    else
                    {
                        amount -= A[temp[j]];
                        cnt--;
                    }
                }
            }

            idx++;
            while (idx < N and amount + arr[idx][0] <= temp[0])
            {
                if (st.find(arr[idx][1]) == st.end())
                {
                    amount += arr[idx][0];
                    cnt++;
                }
                idx++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};
int main(){
    return 0;
}