#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n, m;
    input >> n >> m;

    vector<vector<int>> adjMatrix(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        int u, v;
        input >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    // Вывод матрицы смежности
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            output << adjMatrix[i][j];
            if (j != n) output << " ";
        }
        output << "\n";
    }

    return 0;
}