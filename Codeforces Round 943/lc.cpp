#include <bits/stdc++.h>
using namespace std;
int findRotateSteps(string ring, string key)
{
    int start = 0;
    int n = ring.size();
    unordered_map<char, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[ring[i]].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < key.size(); i++)
    {
        int miny = INT_MAX, ind = -1;
        for (auto j : mp[key[i]])
        {
            int a = abs(j - start);
            a = min(a, n - a);
            if (a <= miny)
            {
                miny = a;
                ind = j;
            }
        }
        ans += miny + 1;
        cout<<ans<<endl;
        start = ind;
    }
    return ans;
}
int main(){
    cout<<findRotateSteps("iotfo","fioot")<<endl;
}