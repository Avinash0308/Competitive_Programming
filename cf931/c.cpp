#include <bits/stdc++.h>
using namespace std;
int query(int x, int y)
{
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, m;
        cin >> n >> m;
        int val = query(1, 1);
        if (val == 0)
        {
            printf("! 1 1\n");
            fflush(stdout);
        }
        else
        {
            
        }
    }
    return 0;
}