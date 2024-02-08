#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int q;
        cin >> q;
        vector<vector<int>> x(q);
        for (int i = 0; i < q; i++)
        {
            int a, b;
            cin >> a >> b;
            x[i] = {b - 1, a - 1, i};
        }
        vector<pair<int, int>> ans(q, {-1, -1});
        sort(x.begin(), x.end());
        int cur = -1;
        vector<int> last(n);
        
        for (int i = 0; i < n; i++)
        {
            last[i] = cur;
            while (i + 1 < n && v[i] == v[i + 1])
            {
                last[i + 1] = cur;
                i++;
            }
            cur = i;
        }

        //-1 -1 1 2 2
        int ind = 0, q_ind = 0;
        while (ind < n && q_ind < q)
        {
            if(last[ind] == -1) ind++;
            if (ind >= x[q_ind][1] && ind <= x[q_ind][0] && last[ind] >= x[q_ind][1] && last[ind] <= x[q_ind][0])
            {
                ans[x[q_ind][2]] = {last[ind]+1, ind+1};
                q_ind++;
            }
            else if(ind < x[q_ind][1] || ind >= x[q_ind][1] && ind <= x[q_ind][0])
            {
                ind++;
            }
            else if(ind > x[q_ind][0]){
                q_ind++;
            }
        }
        for (int i = 0; i < q; i++)
        {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
    return 0;
}