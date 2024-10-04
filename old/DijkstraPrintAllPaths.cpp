#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
#include <stack>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(int source, vector<vector<pair<int, int>>> &adj, vector<int> &dist, vector<int> &prev) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto &neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

void printPath(int node, vector<int> &prev) {
    stack<int> path;
    for (int at = node; at != -1; at = prev[at]) {
        path.push(at);
    }
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    cout << "Enter edges (u, v, weight):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // If the graph is undirected
    }

    vector<int> dist(n, INF);
    vector<int> prev(n, -1);
    int source;
    cout << "Enter source node: ";
    cin >> source;

    dijkstra(source, adj, dist, prev);

    cout << "Shortest distances and paths from source node " << source << ":" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": " << dist[i] << " Path: ";
        printPath(i, prev);
    }

    return 0;
}
