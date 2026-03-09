#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <set>
using namespace std;

void canonBFS(const vector<vector<int>>& arcList, int root, vector<int>& canonArr)
{
    queue<int> q;
    vector<bool> visited(arcList.size(), false);
    visited[root] = true;
    canonArr[root] = 0;
    q.push(root);

    while (!q.empty())
    {
        int V = q.front();
        q.pop();

        for (int U : arcList[V])
        {
            if (!visited[U])
            {
                visited[U] = true;
                canonArr[U] = V;
                q.push(U);
            }
        }
    }
}

int getRoot(const vector<vector<int>>& arcList)
{
    set<int> childs;
    for (int i = 1; i < arcList.size(); i++)
    {
        for (int child : arcList[i])
        {
            childs.insert(child);
        }
    }

    for (int i = 1; i < arcList.size(); i++)
    {
        if (childs.find(i) == childs.end())
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    input >> n;

    vector<vector<int>> arcList(n + 1);
    bool top;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            input >> top;
            if (top) arcList[i].push_back(j);
        }
    }

    int root = getRoot(arcList);
    vector<int> canonArr(n + 1);
    canonBFS(arcList, root, canonArr);

    for (int i = 1; i <= n; i++)
    {
        output << canonArr[i] << " ";
    }

    return 0;
}