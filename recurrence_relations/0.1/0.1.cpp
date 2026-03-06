#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> mosq(n);

	for (int i = 0; i < n; i++)
	{
		cin >> mosq[i];
	}
	vector<int>lilies(n,-1);
	vector<int>path_tracing (n, 0);//вектор для просчета пути
	lilies[0] = mosq[0];
	if (n > 1)
	{
		lilies[1] = -1;
	}
	if (n > 2)
	{
		lilies[2] = mosq[0] + mosq[2];
	}
	for (int i = 3; i < n; i++)
	{
		if (lilies[i - 2] > lilies[i - 3])
		{
			lilies[i] = lilies[i - 2] + mosq[i];
			path_tracing[i] = i - 2;
		}
		else
		{
			lilies[i] = lilies[i - 3] + mosq[i];
			path_tracing[i] = i - 3;
		}
	}
	cout << lilies[n-1] << endl;
	if (lilies[n - 1] != -1)
	{
		vector<int>result_sequence;						 //запись пути в обратном порядке
		for (int i = n - 1; i >= 0; i = path_tracing[i]) //стартуя с последней кувшинки, сдвигаемся на ту, которая указана в векторе последовательности
		{
			result_sequence.push_back(i + 1);
			if (!i) break;
		}
		for (int i = result_sequence.size() - 1; i >= 0; i--)
		{
			cout << result_sequence[i] << " ";
		}
	}
	return 0;
}