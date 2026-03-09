#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

class DSU
{
private:
	vector<int> parent;
	vector<int> sizes;
	int counter;

public:
	DSU (int size)
	{
		parent.resize(size+1);
		sizes.resize(size+1);
		counter = size;
		for (int i = 1; i <= size; i++)
		{
			parent[i] = i;
			sizes[i] = 1;
		}
	}
	int FindSet(int x)
	{
		if (x == parent[x])	return x;

		return parent[x] = this->FindSet(parent[x]);
	}

	void Union(int x, int y)
	{
		int xHead = FindSet(x);
		int yHead = FindSet(y);

		if (xHead != yHead)
		{
			if (sizes[xHead] < sizes[yHead])
			{
				swap(xHead, yHead);
			}
			parent[yHead] = xHead;
			sizes[xHead] += sizes[yHead];
			counter--;
		}
		
	}
	int getGraphComponents() { return counter; }

	friend ostream& operator<<( ostream& out, const DSU& obj)
	{
		
		for (int i = 1; i < obj.parent.size(); i++)
		{
			out << " "<<obj.parent[i] <<" "<<"\t";
		}
		out << endl;

		for (int i = 1; i < obj.parent.size(); i++)
		{
			out << obj.sizes[i] << "\t";
		}
		return out;
	}
};

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	int n; 
	input >> n;
	if (n == 1)
	{
		output << "1";
		return 0;
	}
	int m, q, U, V;
	input >> m >> q;
	
	vector<pair<int, int>> edges(m + 1);
	for (int i = 1; i <= m; i++)
	{
		input >> U >> V;
		edges[i].first = U;
		edges[i].second = V;
	}

	int index;
	vector<bool>isCrushed(m + 1, false);
	vector<int>earthquakes(q + 1);
	for (int i = 1; i <= q; i++)
	{
		input >> index;
		earthquakes[i] = index;
		isCrushed[index] = true;
	}
	DSU data(n);
	for (int i = 1; i <= m; i++)
	{
		if (!isCrushed[i])
		{
			data.Union(edges[i].first, edges[i].second);
		}
	}
	vector<bool> result(q+1, false);
	for (int i = q; i >= 1; i--)
	{
		if (data.getGraphComponents() == 1)		result[i] = true;
		data.Union(edges[earthquakes[i]].first, edges[earthquakes[i]].second);
		//cout << data << endl;
		//cout << "Components: " << data.getGraphComponents() << endl<<endl;
	}

	for (int i = 1; i <= q; i++)
	{
		//cout << result[i];
		output << result[i];
	}
	return 0;
}