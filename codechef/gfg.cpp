#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to perform DFS and calculate the maximum score
pair<long long, bool> dfs(int node,  unordered_map<int, vector<int>>& tree, const vector<int>& a) {
    // Total score for the subtree rooted at the current node
    long long subtree_score = a[node - 1];
    // Number of children (direct edges) connected to the current node
    int direct_edges = tree[node].size();

    // Perform DFS for each child
    for (int child : tree[node]) {
        pair<long long, bool> child_result = dfs(child, tree, a);
        subtree_score += child_result.first;  // Add the score of the child subtree if it's included
    }

    // Check the number of direct edges connected to this node
    if (direct_edges % 2 == 0) {
        // If the number of direct edges is even, we don't include the score of this node
        return {0, false};
    } else {
        // If the number of direct edges is odd, we include the score of this node
        return {subtree_score, true};
    }
}

long long treeGame(int n, const vector<int>& p, const vector<int>& a) {
    // Build the tree using an adjacency list
    unordered_map<int, vector<int>> tree;
    for (int i = 2; i <= n; i++) {
        tree[p[i - 2]].push_back(i);  // Node p[i-2] is the parent of node i
    }

    // Ensure the root node is in the tree (even if it has no children)
    tree[1];

    // Perform DFS from the root node (node 1)
    pair<long long, bool> result = dfs(1, tree, a);

    // The result.first contains the maximum possible score
    return result.first;
}

int main() {
    int n = 3;
    vector<int> p = {1, 1};  // Parent array
    vector<int> a = {1, 2, 3};  // Score array

    cout << treeGame(n, p, a) << endl;  // Output the maximum score

    return 0;
}
