#include <bits/stdc++.h>
using namespace std;


struct TreeNode
{
    int data;
    TreeNode *left, *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<int> &nums)
{
    if (nums.empty())
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(nums[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (i < nums.size())
    {
        TreeNode *curr = q.front();
        q.pop();
        if (i < nums.size())
        {
            curr->left = new TreeNode(nums[i++]);
            q.push(curr->left);
        }
        if (i < nums.size())
        {
            curr->right = new TreeNode(nums[i++]);
            q.push(curr->right);
        }
    }
    return root;
}
bool isspecial(TreeNode *root)
{
    if (!root->left && !root->right)
        return true;
    return false;
}
int helper(TreeNode *root, int &ans)
{
    if (!root)
        return 0;
    if (isspecial(root))
        return root->data;
    else
    {
        int x = helper(root->left, ans);
        int y = helper(root->right, ans);
        if (root->left && root->right)
        {
            ans = max(ans, x + y + root->data);
            return max(x, y) + root->data;
        }
        if (!root->left)
            return y + root->data;
        else
            return x + root->data;
    }
}
int maxPathSum(TreeNode *root)
{
    int ans = INT_MIN;
    int x = helper(root, ans);
    if (root->left and root->right)
    {
        return ans;
    }
    return max(ans, x);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    TreeNode *root = buildTree(v);
    cout << maxPathSum(root) << endl;
    return 0;
}