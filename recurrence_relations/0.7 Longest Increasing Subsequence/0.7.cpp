#include <iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string>
using namespace std;

int UpperBound(const vector<int>& arr, int x)
{
	int q = 0;
	int r = arr.size();
	while (q < r)
	{
		int k = (q + r) / 2;

		if (x < arr[k])		   r = k;
		else if (x >= arr[k])  q = k + 1;
	}
	return q;
}

int SizeOfLongestIncreasingSubSeq(const vector<int>& X, vector<int>& DP)
{
	for (int i = 0; i < X.size(); i++)
	{
		int x = X[i];
		int index = UpperBound(DP, x);

		if (index < DP.size()) 
		{
			DP[index] = x; 
		}
		else 
		{
			DP.push_back(x); 
		}
	}
	return DP.size();
}

int main()
{ 
	ifstream input("input.txt");
	ofstream output("output.txt");

	int size;
	input >> size;

	vector<int> seq(size);
	for (int i = 0; i < size; i++)
	{
		input >> seq[i];
	}

	vector<int> DP;

	int LIS_length = SizeOfLongestIncreasingSubSeq(seq, DP);
	output << LIS_length;
}
