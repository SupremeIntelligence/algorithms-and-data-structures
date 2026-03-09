#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<set>
using namespace std;

void tagsDFS(const vector<vector<int>>& arcList, vector<int>& tags,vector<bool>& visited, int start)
{
	visited[start] = true;
	tags[start] = tags[0];
	tags[0]++;
	

	for (int U : arcList[start])
	{
		if (!visited[U])
		{
			tagsDFS(arcList, tags, visited, U);
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
	vector<int> temp_list(n + 1);
	
	bool top;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			input >> top;
			if (top == true)	arcList[i].push_back(j);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		sort(arcList[i].begin(), arcList[i].end());
	}

	vector<int>tags(n + 1, -1);
	tags[0] = 1; 

	vector<bool>visited(arcList.size(), false);
	for (int i = 1; i < tags.size(); i++)
	{
		if (!visited[i])
		{
			tagsDFS(arcList, tags, visited, i);
		}
	}
	
	
	for (int i = 1; i <= n; i++)
	{
		//cout << tags[i] << " ";
		output << tags[i] << " ";
	}

	return 0;
}