#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

struct TrieNode
{
    int value;
    TrieNode *Child[2];
};
TrieNode *getNode()
{
    TrieNode *newNode = new TrieNode;
    newNode->value = 0;
    newNode->Child[0] = newNode->Child[1] = NULL;
    return newNode;
}
void insert(TrieNode *root, int key)
{
    TrieNode *temp = root;
    for (int i = INT_SIZE - 1; i >= 0; i--)
    {
        bool current_bit = (key & (1 << i));
        if (temp->Child[current_bit] == NULL)
            temp->Child[current_bit] = getNode();

        temp = temp->Child[current_bit];
    }
    temp->value = key;
}
int minXORUtil(TrieNode *root, int key)
{
    TrieNode *temp = root;

    for (int i = INT_SIZE - 1; i >= 0; i--)
    {
        bool current_bit = (key & (1 << i));
        if (temp->Child[current_bit] != NULL)
            temp = temp->Child[current_bit];
        else if (temp->Child[1 - current_bit] != NULL)
            temp = temp->Child[1 - current_bit];
    }
    return key ^ temp->value;
}
f
int calculateAns(int N, int M, vector<int> parents, vector<int> latency, int q, vector<int> queries)
{
    unordered_map<int, vector<int>> e;
    for (int i = 0; i < N - 1; i++)
    {
        e[parents[i]].push_back(i + 2);
    }
    vector<int> dp(N + 1, INT_MAX);
    TrieNode *root = getNode();
    insert(root,latency[0]);
    
}

int main()
{
    return 0;
}