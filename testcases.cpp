#include <bits/stdc++.h>
using namespace std;
string solve(vector<int> &nums, int k)
{
    int n = nums.size();
    int res_and = (1LL<<31)-1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if ((nums[i] & k) == k)
        {
            res_and = res_and & nums[i];
            count++;
        }
    }
    if (res_and == k && count > 0)
    {
        return "True";
    }
    else
    {
        return "False";
    }
}
int main()
{
    vector<vector<int>> v;
    int t = 50;
    int test = t;
    while (t--)
    {
        int siz = rand() % 30 + 1;
        vector<int> cur;
        for (int i = 0; i < siz; i++)
        {
            int maxy = 1e9;
            int val = rand() % (maxy);
            cur.push_back(val);
        }
        v.push_back(cur);
    }
    cout << endl;
    vector<pair<int,string>> res;
    for (int i = 0; i < test; i++)
    {
        int maxy = 1e9;
        int k;
        string ans;
        if(i%3){
            k = rand() % (maxy);
            ans = solve(v[i],k);
        }
        else{
            int th = rand()%(v[i].size());
            k = v[i][th];
            ans = solve(v[i],k);
        }
        res.push_back({k,ans});
    }
    for(int i = 0; i<test; i++){
        cout<<endl<<"Input: nums = [ ";
        int s = v[i].size();
        int val1 = res[i].first;
        string val2 = res[i].second;
        for(int j = 0; j<s; j++){
            cout<<v[i][j]<<", ";
        }
        cout<<"] , k = "<<val1<<endl;
        cout<<"Output: "<<val2<<endl;
    }
    return 0;
}