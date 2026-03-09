#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>

using namespace std;

void tagsBFS(const vector<vector<int>>& arcList, vector<int>& tags) {
    int tag = 1;
    queue<int> q;
    vector<bool> visited(arcList.size(), false);

    for (int i = 1; i < tags.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            tags[i] = tag++;
            q.push(i);

            while (!q.empty()) {
                int V = q.front();
                q.pop();

                for (int U : arcList[V]) {
                    if (!visited[U]) {
                        visited[U] = true;
                        tags[U] = tag++;
                        q.push(U);
                    }
                }
            }
        }
    }
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    input >> n;
    vector<vector<int>> arcList(n + 1);

    bool edge;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            input >> edge;
            if (edge) arcList[i].push_back(j);
        }
        sort(arcList[i].begin(), arcList[i].end()); // меньший номер вершины при неоднозначности
    }

    vector<int> tags(n + 1, -1);
    tagsBFS(arcList, tags);

    for (int i = 1; i <= n; i++) {
        output << tags[i] << " ";
    }

    return 0;
}