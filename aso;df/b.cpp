#include <bits/stdc++.h>
using namespace std;
class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;
};
int test(vector<int> &v)
{
    int n = v.size();
    vector<int> ans(n);
    int res = INT_MIN;
    for (int i = n - 1; i >= 1; i--)
    {
        int val1 = (i < n - 3) ? ans[i + 3] : 0;
        int val2 = (i < n - 2) ? ans[i + 2] : 0;
        ans[i] = v[i] + max({0, val1, val2});
        res = max(res, ans[i]);
    }
    ans[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int val1 = (i < n - 4) ? ans[i + 4] : 0;
        int val2 = (i < n - 3) ? ans[i + 3] : 0;
        ans[i] = v[i] + max({0, val1, val2});
        res = max(res, ans[i]);
    }
    return res;
}
int nonNeighbors(SinglyLinkedListNode *root)
{
    vector<int> v;
    SinglyLinkedListNode *h = root;
    do
    {
        v.push_back(h->data);
        h = h->next;
    } while (h != root);
    int n = v.size();
    vector<int> ans(n);
    int res = INT_MIN;
    for (int i = n - 1; i >= 1; i--)
    {
        int val1 = (i+2 <= n-1) ? ans[i + 2] : 0;
        int val2 = (i+3 <= n-1) ? ans[i + 3] : 0;
        ans[i] = v[i] + max({0, val1, val2});
        res = max(res, ans[i]);
    }
    ans[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int val1 = (i+2 <= n - 2) ? ans[i + 2] : 0;
        int val2 = (i+3 <= n - 2) ? ans[i + 3] : 0;
        ans[i] = v[i] + max({0, val1, val2});
        res = max(res, ans[i]);
    }
    return res;
}

int main()
{
    vector<int> v = {4, 3, 2, 1, 5};
    cout << test(v) << endl;
    return 0;
}