#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> m;
unordered_map<int,vector<pair<int,int>>> v;

int shortestPath(Graph& graph, int source, int destination) {
    int n = graph.nodes;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap
    vector<vector<int>> dist(n, vector<int>(1024, INF)); // 1024 is the maximum possible weight

    // Initializing the distance for the source node
    dist[source][0] = 0;

    // Push the source node into the priority queue
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int current_dist = pq.top().first;
        pq.pop();

        // Check if the current distance is already updated
        if (current_dist > dist[u][current_dist & 1023]) {
            continue;
        }

        // Relaxation step
        for (auto& edge : graph.adjList[u]) {
            int v = edge.first;
            int weightUV = edge.second;
            int new_dist = dist[u][current_dist & 1023] + weightUV;

            if (new_dist < dist[v][weightUV & 1023]) {
                dist[v][weightUV & 1023] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }

vector<int> getMinimumCost(int g_nodes, vector<int> &g_from, vector<int> &g_to, vector<int> g_weight, vector<vector<int>> &queries){
    for(int i = 0; i<g_nodes; i++){
        m[g_from[i]].push_back({g_to[i],g_weight[i]});
        m[g_to[i]].push_back({g_from[i],g_weight[i]});
    }
    int n = queries.size();
    vector<int> ans(n);
    for(int i = 0;i <n; i++){
        int a = queries[i][0], b = queries[i][1];
        if(m.find({a,b}) != 0){
            ans[i] = m[{a,b}];
        }
        else{
            dfs()
        }
    }
}

int main(){
    return 0;
}