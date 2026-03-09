#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n, m;
    input >> n >> m;

    vector<vector<int>> arcList(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        input >> u >> v;
        arcList[u].push_back(v);
        arcList[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        output << arcList[i].size();
        for (int neighbor : arcList[i]) {
            output << " " << neighbor;
        }
        output << "\n";
    }

    return 0;
}