#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

struct Path {
    long long length;
    vector<int> cities;

    bool operator>(const Path& other) const {
        return length > other.length;
    }
};

void Find_K_ShortestPath(const int start, const int end, const int K, const vector<vector<pair<int, int>>>& arcList, vector<priority_queue<long long>>& dist, ostream& out)
{
    priority_queue<Path, vector<Path>, greater<>> pq;
    pq.push({ 0, {start} });

    Path current;

    while (!pq.empty()) {
        current = pq.top();
        pq.pop();

        int V = current.cities.back();

        if (dist[end].size() >= K && current.length > dist[end].top())
        {
            continue;
        }

        if (dist[V].size() < K) {
            dist[V].push(current.length);
        }
        else if (current.length < dist[V].top())
        {
            dist[V].pop();
            dist[V].push(current.length);
        }

        if (V == end && dist[end].size() == K)
        {
            break;
        }

        //  
        for (const pair<int, int>& neighbor : arcList[V])
        {
            int U = neighbor.first;
            int lengthU = neighbor.second;

            if (dist[U].size() < K || current.length + lengthU < dist[U].top()) {
                Path newPath = current;
                newPath.length += lengthU;
                newPath.cities.push_back(U);
                pq.push(newPath);
            }
        }
    }

    out << current.length << endl;
    for (int city : current.cities) {
        out << city << " ";
    }
}


int main() {

    ifstream input("input.in");
    ofstream output("output.out");
    int n, m;
    input >> n >> m;

    vector<vector<pair<int, int>>> arcList(n + 1);
    int U, V, W;
    for (int i = 0; i < m; i++)
    {
        input >> U >> V >> W;
        arcList[U].push_back({ V, W });
    }

    /*for (int i = 1; i <= n; i++)
    {
        cout << i << ": " << endl;
        for (int j = 0; j < arcList[i].size(); j++)
        {
            cout << arcList[i][j].first << "\tlength: " << arcList[i][j].second << endl;
        }
        cout << endl << endl;
    }*/

    int A, B;
    input >> A >> B;

    int k = 2;
    //vector<vector<long long>> distances(n + 1);
    vector<priority_queue<long long>> distances(arcList.size()); //    K 

    Find_K_ShortestPath(A, B, k, arcList, distances, output);
    //PathTracing(result, output);

    return 0;
}