#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Edge {
    int friendId;
    int weight;
    Edge(int friendId, int weight) : friendId(friendId), weight(weight) {}
};

void dfs(int node, std::vector<std::vector<Edge>>& graph, std::vector<bool>& visited, int& count) {
    visited[node] = true;
    count++;
    for (const Edge& edge : graph[node]) {
        if (!visited[edge.friendId]) {
            dfs(edge.friendId, graph, visited, count);
        }
    }
}

int maxProductInGroup(int friends_nodes, std::vector<int>& friends_from, std::vector<int>& friends_to, std::vector<int>& weight) {
    std::unordered_map<int, unordered_map<int,vector<int>>> companies;
    for (int i = 0; i < friends_from.size(); i++) {
        int friend1 = friends_from[i];
        int friend2 = friends_to[i];
        int w = weight[i];
        companies[friend1][w].push_back(friend2);
        companies[friend2][w].push_back(friend1);
    }
    map<pair<int,int>,int> m;
    int maxy_group = 0;
    int ans = 0;
    for(auto i : companies){
        
        int ind = i.first;
        for(auto j: i){
            visit[ind] = 1;
            int com = j.first;
            int node = 1;
            for(auto )
        }

    }
}

int main() {
    int friends_nodes = 4;
    std::vector<int> friends_from = {1, 1, 2, 2, 2};
    std::vector<int> friends_to = {2, 2, 3, 3, 4};
    std::vector<int> weight = {1, 2, 1, 3, 3};

    int maxProduct = maxProductInGroup(friends_nodes, friends_from, friends_to, weight);
    std::cout << "Maximal product of friends in the largest group: " << maxProduct << std::endl;

    return 0;
}
