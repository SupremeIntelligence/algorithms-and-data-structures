#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

class FenwickTree
{
private:
	vector<long long> tree;

public:
	FenwickTree(int size) : tree(size+1, 0) {};

	void add(int index,long long value)
	{
		for (++index; index < tree.size(); index += (index & -index))		//(index & -index) - вычисление младшего значащего бита
		{
			tree[index] += value;											
		}
	}

	long long sum(int Rrange)
	{
		long long result = 0;
		for (++Rrange; Rrange > 0; Rrange -= (Rrange & -Rrange))
		{
			result += tree[Rrange];
		}
		return result;
	}
	long long sum(int Lrange, int Rrange)
	{
		return sum(Rrange - 1) - sum(Lrange - 1);
	}
};

int main()
{
	//ifstream cin("cin.txt");
	int n, q;
	cin >> n;
	//vector<long long> numbers(n);

	FenwickTree tree(n);
	int value;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		//cin >> numbers[i];
		tree.add(i, value);
	}
	cin >> q;
	string action;
	int index, Lrange, Rrange;
	long long x;
	for (int i = 0; i < q; i++)
	{
		cin >> action;
		if (action[0] == 'A')
		{
			cin >> index >> x;
			//numbers[index] += x;
			tree.add(index, x);
		}
		else
		{
			cin >> Lrange >> Rrange;
			/*long long sum = 0;
			for (int i = Lrange; i < Rrange; i++)
			{
				sum += numbers[i];
			}*/
			cout << tree.sum(Lrange, Rrange) << endl;
		}
	}
	return 0;
}