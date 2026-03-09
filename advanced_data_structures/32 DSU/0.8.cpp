#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

class DSU
{
private:
	vector<int> parent;
	vector<int> sizes;
	int counter;

public:
	DSU(int size)
	{
		parent.resize(size + 1);
		sizes.resize(size + 1);
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

	friend ostream& operator<<(ostream& out, const DSU& obj)
	{

		for (int i = 1; i < obj.parent.size(); i++)
		{
			out << " " << obj.parent[i] << " " << "\t";
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
	ifstream input("equal-not-equal.in");
	ofstream output("equal-not-equal.out");
	int n, m;
	input >> n >> m;

	DSU data(n);
	vector<pair<int, int>> inequalities;
	string xStr, yStr, option;
	int x, y;
	for (int i = 0; i < m; i++)
	{
		input >> xStr >> option >> yStr;
		xStr.erase(0, 1);
		yStr.erase(0, 1);
		x = stoi(xStr);
		y = stoi(yStr);

		if (option == "==")
		{
			data.Union(x, y);
			//cout << data << endl;
		}
		else
		{
			inequalities.push_back({ x, y });
			//cout << x << "\t" << y << endl;
		}
	}
	

	for (pair<int,int> item : inequalities)
	{
		if (data.FindSet(item.first) == data.FindSet(item.second))
		{
			//cout << data.FindSet(item.first) << data.FindSet(item.second) << endl;
			//cout << "NO";
			output << "NO";
			return 0;
		}
	}
	//cout << "Yes";
	output << "Yes";
	return 0;
}