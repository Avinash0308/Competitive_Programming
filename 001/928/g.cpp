#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    vector<Node *> childs;
    Node *parent;
    char val;
    Node(char v)
    {
        val = v;
        parent = NULL;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        unordered_map<int, Node *> mp;
        for (int i = 2; i <= n; i++)
        {
            int val;
            cin >> val;
            Node *parent;
            Node *child = new Node(i);
            mp[i] = child;
            if (mp.count(val) != 0)
                parent = mp[val];
            else
            {
                parent = new Node(val);
                mp[val] = parent;
            }
            parent->childs.push_back(child);
            child->parent = parent;
        }
        for (int i = 1; i <= n; i++)
        {
            char t;
            cin >> t;
            mp[i]->val = t;
        }
        
    }
    return 0;
}