#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX; // Infinity value

// Function to calculate the bitwise AND of two numbers
int bitwiseAND(int a, int b) {
    return a & b;
}

// Graph class definition
class Graph {
public:
    int nodes;
    vector<vector<pair<int, int>>> adjList; // Adjacency list representing the graph

    Graph(int n) : nodes(n), adjList(n) {}

    // Function to add an undirected edge with weight
    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight);
    }
};

// Dynamic programming function to find the minimum cost
vector<int> minCostWalk(Graph& graph, vector<pair<int, int>>& queries) {
    int n = graph.nodes;
    long long int maxWeight = 1e9+7; // Assuming weights are between 0 and 1023 (inclusive)

    // Initialize DP table
    vector<vector<int>> dp(n, vector<int>(maxWeight, INF));
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 0; // Base case: cost to reach node i with AND 0 is 0
    }

    // Dynamic programming
    for (int w = 0; w < maxWeight; ++w) {
        for (int u = 0; u < n; ++u) {
            for (auto& edge : graph.adjList[u]) {
                int v = edge.first;
                int weightUV = edge.second;
                int newWeight = bitwiseAND(w, weightUV);
                dp[v][newWeight] = min(dp[v][newWeight], dp[u][w] + weightUV);
            }
        }
    }

    // Process queries
    vector<int> results;
    for (auto& query : queries) {
        int u = query.first;
        int v = query.second;
        int minCost = *min_element(dp[v].begin(), dp[v].end());
        results.push_back((minCost == INF) ? -1 : minCost);
    }

    return results;
}

int main() {
    int n, m, q;
    cin >> n >> m; // Number of nodes and edges in the graph
    Graph graph(n);

    // Input the graph edges and weights
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    cin >> q; // Number of queries
    vector<pair<int, int>> queries(q);

    // Input the queries
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    // Find and output the results
    vector<int> results = minCostWalk(graph, queries);
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}

