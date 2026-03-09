#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int m, c, n;

void setHash(vector<int>& hash, int key)
{
	for (int i = 0; i < m; i++)
	{
		int hashValue = ((key % m) + c * i) % m;
		if (hash[hashValue] == -1)
		{
			hash[hashValue] = key;
			return;
		}
		if (hash[hashValue] == key)
		{
			return;
		}
	}
}

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");

	input >> m >> c >> n;
	int key;

	vector<int> hash(m, -1);

	for (int i = 0; i < n; i++)
	{
		input >> key;
		setHash(hash, key);
	}

	for (int i = 0; i < m; i++)
	{
		output << hash[i] << " ";
	}
	
	return 0;
}