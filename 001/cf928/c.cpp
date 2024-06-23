#include <bits/stdc++.h>
using namespace std;
char query(int a, int b, int c, int d)
{
    printf("? %d %d %d %d\n", a, b, c, d);
    fflush(stdout);
    char x;
    cin>>x;
    fflush(stdout);
    return x;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int max_ind = 0;
        for (int i = 1; i < n; i++)
        {
            char out = query(max_ind, max_ind, i, i);
            if (out == '<')
                max_ind = i;
        }
        vector<int> max_or_val;
        int max_or = 0;
        max_or_val.push_back(0);
        for (int i = 1; i < n; i++)
        {
            char out = query(max_ind, max_or, max_ind, i);
            if (out == '=')
            {
                max_or_val.push_back(i);
            }
            else if (out == '<')
            {
                max_or = i;
                max_or_val.resize(0);
                max_or_val.push_back(i);
            }
        }
        int min_ind = max_or_val[0];
        for (int i = 1; i < max_or_val.size(); i++)
        {
            char out = query(min_ind, min_ind, max_or_val[i], max_or_val[i]);
            if (out == '>')
                min_ind = max_or_val[i];
        }
        printf("! %d %d\n", min_ind, max_ind);
        fflush(stdout);
    }
    return 0;
}