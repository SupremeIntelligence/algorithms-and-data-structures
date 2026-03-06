#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<fstream>
using namespace std;


int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");

	int s;
	input >> s;
	vector<int> mtrx(s + 1); //количество строк i-й матрицы = количество стобцов i-1-й матрицы // количество столбцов i-й = количество строк i+1-й
	int temp = 0;
	for (int i = 0; i < s; i++)
	{
		input >> mtrx[i] >> temp;
	}

	mtrx[s] = temp; //количество столбцов последней матрицы

	/*cout << endl << endl;
	for (int i = 0; i < s+1; i++)
	{
		cout << mtrx[i] << endl;
	}

	cout << endl<<endl;*/

	vector<vector<int>> DP(s, vector<int>(s, 0));
	int min_value = 0;

	//движение по побочным диагоналям матрицы ДП
	for (int l = 2; l <= s; l++)						//количество цепочек матриц
	{
		for (int i = 0; i < s - l + 1; i++)
		{
			int j = i + l - 1;
			DP[i][j] = INT_MAX;
			for (int k = i; k < j; k++)
			{
				min_value = DP[i][k] + DP[k + 1][j] + mtrx[i] * mtrx[k + 1] * mtrx[j + 1];
				if (min_value < DP[i][j])
				{
					DP[i][j] = min_value;
				}
				//cout << "i = " << i << " j = " << j << " k = " << k << endl;
			}
		}
	}

	//cout << endl;
	//for (int i = 0; i < s; i++)
	//{
	//	for (int j = 0; j < s; j++)
	//	{
	//		cout << DP[i][j] << "\t";
	//	}
	//	cout << endl;
	//}
	output << DP[0][s - 1];
}
