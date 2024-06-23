#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9; // A very large value representing infinity

struct Edge {
    int to;
    int distance;

    Edge(int _to, int _distance) : to(_to), distance(_distance) {}
};

void shortestDistance(int N, const vector<vector<Edge>>& graph, int start, int end) {
    vector<vector<int>> distance(N + 1, vector<int>(2, INF)); // distance[i][0] for state highway, distance[i][1] for national highway
    distance[start][0] = distance[start][1] = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {start, 0}});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int city = pq.top().second.first;
        int usedNational = pq.top().second.second;
        pq.pop();

        if (dist > distance[city][usedNational])
            continue;

        for (const Edge& edge : graph[city]) {
            int newDist = dist + abs(edge.distance);
            int newUsedNational = usedNational + (edge.distance < 0 ? 1 : 0);

            if (newUsedNational > 1)
                continue;

            if (newDist < distance[edge.to][newUsedNational]) {
                distance[edge.to][newUsedNational] = newDist;
                pq.push({newDist, {edge.to, newUsedNational}});
            }
        }
    }

    int result = min(distance[end][0], distance[end][1]);
    if (result == INF)
        cout << "No valid path exists." << endl;
    else
        cout << "Shortest distance between City " << start << " and City " << end << ": " << result << endl;
}

int main() {
    int N, M; // N: number of cities, M: number of roads
    cin >> N >> M;

    vector<vector<Edge>> graph(N + 1);
    vector<vector<int>> v(M,vector<int> (4));
    for (int i = 0; i < M; ++i) {
        cin>>v[i][0]>>v[i][1]>>v[i][2]>>v[i][3];

        
    }

    int start, end;
    cin >> start >> end;
    for(int i = 0; i<M; i++){
        int from, to, stateDistance, nationalDistance;
        from = v[i][0];
        to = v[i][1];
        stateDistance = v[i][2];
        nationalDistance = v[i][3];
        graph[from].emplace_back(to, stateDistance);
        graph[to].emplace_back(from, stateDistance);
        graph[from].emplace_back(to, -nationalDistance); // Using negative value to distinguish national highway
        graph[to].emplace_back(from, -nationalDistance);
    }
    shortestDistance(N, graph, start, end);

    return 0;
}
