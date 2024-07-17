#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
struct node
{
    int mn, mx, sum;
    node(int mn = -1, int mx = -1, int sum = 0) : mn(mn), mx(mx), sum(sum) {}
};
struct segTree
{
    vector<node> seg;
    segTree(int n)
    {
        seg.resize(n << 2);
    }
    node merge(node a, node b)
    {
        if (a.mn == -1)
            return b;
        if (b.mn == -1)
            return a;
        a.mn = min(a.mn, b.mn);
        a.mx = max(a.mx, b.mx);
        (a.sum += b.sum) %= mod;
        return a;
    }
    void build(vector<pair<int, int>> &v, int n, int s, int e)
    {
        if (s == e)
        {
            seg[n] = node(v[s - 1].first, v[s - 1].first, 0);
            return;
        }
        build(v, n * 2, s, (s + e) / 2);
        build(v, n * 2 + 1, (s + e) / 2 + 1, e);
        seg[n] = merge(seg[n * 2], seg[n * 2 + 1]);
    }
    node get(int n, int s, int e, int l, int r)
    {
        if (seg[n].mn > r || l > seg[n].mx)
            return node(-1, -1, 0);
        if (seg[n].mn >= l && r >= seg[n].mx)
            return seg[n];
        return merge(get(n * 2, s, (s + e) / 2, l, r), get(n * 2 + 1, (s + e) / 2 + 1, e, l, r));
    }
    void update(int n, int s, int e, int idx, int val)
    {
        if (s == e)
        {
            seg[n] = node(seg[n].mn, seg[n].mx, (seg[n].sum + val) % mod);
            return;
        }
        if (idx <= (s + e) / 2)
            update(n * 2, s, (s + e) / 2, idx, val);
        else
            update(n * 2 + 1, (s + e) / 2 + 1, e, idx, val);
        seg[n] = merge(seg[n * 2], seg[n * 2 + 1]);
    }
};
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    vector<int> pw(20);
    for (int i = 0, k = 1; i <= 18; i++, k *= 10)
        pw[i] = k;
    pw[19] = LLONG_MAX;
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        set<int> nums;
        for (auto &it : v)
            cin >> it, nums.insert(it);
        map<int, int> mp;
        int id = 0;
        for (auto &it : nums)
            mp[it] = ++id;
        segTree st(id);
        vector<pair<int, int>> a(mp.begin(), mp.end());
        st.build(a, 1, 1, id);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            (ans += (n - i) * st.get(1, 1, id, max(0LL, pw[x - 1] - v[i]), max(0LL, pw[x] - v[i] - 1)).sum);
            st.update(1, 1, id, mp[v[i]], i + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}