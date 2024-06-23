#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
long solve(vector<int> &visited, unordered_map<int, vector<int>> &v, int node, int K, long &result)
{
    if (visited[node])
        return 0;
    visited[node] = 1;
    int n = v[node].size();
    long long int cur = 1;
    for (int i = 0; i < n; i++)
    {
        cur += solve(visited, v, v[node][i], K, result);
    }
    if (node != 1)
        result += ((cur + K - 1) / K);
    return cur;
}
long getMinOperations(int k, int g_nodes, vector<int> &from, vector<int> &to)
{
    // Initialize the graph as an adjacency list
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < from.size(); ++i)
    {
        graph[from[i]].push_back(to[i]);
        graph[to[i]].push_back(from[i]);
    }
    long result = 0;
    vector<int> visited(g_nodes + 1);
    solve(visited, graph, 1, k, result);
    return result;
}

int main()
{
    int g_nodes = 6;
    vector<int> g_from = {2, 2, 2, 3, 4};
    vector<int> g_to = {1, 6, 3, 5, 3};
    int K = 3;
    int result = getMinOperations(K, g_nodes, g_from, g_to);
    cout << result << endl;
    return 0;
}
