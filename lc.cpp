#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        int len = meetings.size();
        vector<int> secret(n);
        secret[0] = secret[firstPerson] = 1;
        for (int i = 0; i < len; i++)
        {
            swap(meetings[i][0], meetings[i][2]);
        }
        sort(meetings.begin(), meetings.end());
        for (int i = 0; i < len; i++)
        {
            int ind = i;
            unordered_map<int, vector<int>> mp;
            queue<int> q;
            while (ind < len - 1 && meetings[ind][0] == meetings[ind + 1][0])
            {
                mp[meetings[ind][1]].push_back(meetings[ind][2]);
                mp[meetings[ind][2]].push_back(meetings[ind][1]);
                if (secret[meetings[ind][1]])
                    q.push(meetings[ind][1]);
                if (secret[meetings[ind][2]])
                    q.push(meetings[ind][2]);
                ind++;
            }
            mp[meetings[ind][1]].push_back(meetings[ind][2]);
            mp[meetings[ind][2]].push_back(meetings[ind][1]);
            if (secret[meetings[ind][1]])
                q.push(meetings[ind][1]);
            if (secret[meetings[ind][2]])
                q.push(meetings[ind][2]);
            while (!q.empty())
            {
                int val = q.front();
                q.pop();
                for (auto j : mp[val])
                {
                    if (secret[j] == 0)
                    {
                        secret[j] = 1;
                        q.push(j);
                    }
                }
            }
            i = ind;
        }
        vector<int> have_secret;
        for (int i = 0; i < n; i++)
        {
            if (secret[i])
            {
                have_secret.push_back(i);
            }
        }
        return have_secret;
    }
};
int main()
{

    return 0;
}