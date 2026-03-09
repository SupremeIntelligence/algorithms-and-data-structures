#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<set>
using namespace std;

void BFS(const vector<vector<int>>& arcList, int root, vector<int>& canonArr)
{
	queue<int> q;
	vector<bool>visited(arcList.size(), false);
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
	set<int>childs;

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
}

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	int n;
	input >> n;
	vector<vector<int>> arcList(n + 1);
	int U, V;
	for (int i = 1; i < n; i++)
	{
		input >> U >> V;
		arcList[U].push_back(V);
	}

	int root = getRoot(arcList);
	/*for (int i = 1; i <= n; i++)
	{
		if (!arcList[i].empty())
		{
			root = i;
			break;
		}
	}*/
	//if (n == 1)	root = ; !!!!!!!
				
	/*cout <<endl<<endl<< "root - " << root << endl<<endl;
	for (int i = 1; i <= n; i++)
	{
		cout << i << ":\t";
		for (int j = 0; j < arcList[i].size(); j++)
		{
			cout << arcList[i][j] << " ";
		}
		cout << endl;
	}*/
	vector<int>canonArr(n + 1);
	BFS(arcList, root, canonArr);

	//cout << endl << endl << "Canon array: " << endl;
	for (int i = 1; i <= n; i++)
	{
		//cout << canonArr[i] << " ";
		output << canonArr[i] << " ";
	}

	return 0;
}