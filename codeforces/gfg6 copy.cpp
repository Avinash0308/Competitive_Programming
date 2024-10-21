class Solution
{
public:
    struct Trie
    {
        int data;
        Trie *v[2];
    };

    Trie *node()
    {
        Trie *temp = new Trie();
        temp->data = 0;
        temp->v[0] = temp->v[1] = NULL;
        return temp;
    }

    void add(Trie *h, int cur)
    {
        Trie *temp = h;
        for (int i = 31; i >= 0; i--)
        {
            bool pos = cur & (1 << i);
            if (temp->v[pos] == NULL)
                temp->v[pos] = node();
            temp = temp->v[pos];
        }
        temp->data = cur;
    }

    int solve(Trie *h, int cur)
    {
        Trie *temp = h;
        for (int i = 31; i >= 0; i--)
        {
            bool pos = cur & (1 << i);
            if (temp->v[1 - pos] != NULL)
                temp = temp->v[1 - pos];
            else if (temp->v[pos] != NULL)
                temp = temp->v[pos];
        }
        return cur ^ (temp->data);
    }

    vector<int> solve2(vector<int> &v)
    {
        int n = v.size();
        vector<int> res(n);
        Trie *h = node();
        add(h, 0);
        int ans = INT_MIN, cur = 0;
        for (int i = 0; i < n; i++)
        {
            cur = cur ^ v[i];
            add(h, cur);
            ans = max(ans, solve(h, cur));
            res[i] = ans;
        }
        return res;
    }
    int maximumSumOfXorSums(int n, vector<int> &arr)
    {
        // code here
        vector<int> l = solve2(arr);
        reverse(arr.begin(), arr.end());
        vector<int> r = solve2(arr);
        reverse(r.begin(), r.end());
        int ans = INT_MIN;
        for (int i = 0; i < n - 1; i++)
        {
            ans = max(ans, l[i] + r[i + 1]);
        }
        return ans;
    }
};