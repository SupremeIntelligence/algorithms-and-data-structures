#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <limits>
using namespace std;

void DijkstraSearch(const vector<vector<pair<int,int>>>& arcList, vector<long long>& dist) {
    int n = arcList.size() - 1;
    dist.assign(n + 1, LLONG_MAX);
    vector<bool> processed(n + 1, false);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> q;

    dist[1] = 0; // стартовая вершина 1
    q.push({0, 1});

    while (!q.empty()) {
        auto [distV, V] = q.top();
        q.pop();
        if (processed[V]) continue;
        processed[V] = true;

        for (auto [U, w] : arcList[V]) {
            if (dist[V] + w < dist[U]) {
                dist[U] = dist[V] + w;
                q.push({dist[U], U});
            }
        }
    }
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    int n, m;
    input >> n >> m;

    vector<vector<pair<int,int>>> arcList(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        input >> u >> v >> w;
        arcList[u].push_back({v, w});
        arcList[v].push_back({u, w}); // граф неориентированный
    }

    vector<long long> dist;
    DijkstraSearch(arcList, dist);

    output << dist[n] << endl;
    return 0;
}