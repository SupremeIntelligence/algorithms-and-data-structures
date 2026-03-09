#include <iostream>
#include<vector>
using namespace std;

bool BinSearch(const vector<int>& arr, int x)
{
	int q = 0;
	int r = arr.size();
	while (q < r)
	{
		int k = (q + r) / 2;

		if (x == arr[k])		return true;
		else if (x < arr[k])	r = k;
		else					q = k + 1;
	}
	return false;
}

int LowerBound(const vector<int>& arr, int x)
{
	int q = 0;
	int r = arr.size();
	while (q < r)
	{
		int k = (q + r) / 2;

		if (x <= arr[k])		r = k;
		else if (x > arr[k])	q = k + 1;
		else					return arr.size();
	}
	return q;
}

int UpperBound(const vector<int>& arr, int x)
{
	int q = 0;
	int r = arr.size();
	while (q < r)
	{
		int k = (q + r) / 2;

		if (x < arr[k])		   r = k;
		else if (x >= arr[k])  q = k + 1;
		else				   return arr.size();
	}
	return q;
}


int main()
{
	int n;
	cin >> n;
	vector<int> numbers(n);

	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	int k;
	cin >> k;
	int x;
	for (int i = 0; i < k; i++)
	{
		cin >> x;
		cout << BinSearch(numbers, x) << " " << LowerBound(numbers, x) << " " << UpperBound(numbers, x) << endl;
	}
}