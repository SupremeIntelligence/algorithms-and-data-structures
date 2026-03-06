#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int SizeOfLongestSubSeq(const vector<int>& A, const vector<int>& B, vector<vector<int>>& DP)
{
	int size = DP.size();
	for (int i = 1; i < size; i++)
	{
		for (int j = 1; j < size; j++)
		{
			if (A[i-1] == B[j-1])
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else
			{
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}
	return DP[size-1][size-1];
}

void RestoreLongestSubSeq(const vector<int>& A, const vector<int>& B, vector<vector<int>>& DP, int LCS_length)
{
	int size = DP.size();

	vector <pair<int, int>> LCS_index (LCS_length);

	for (int i = size - 1, j = size - 1; i > 0 && j > 0; )
	{
			if (A[i - 1] == B[j - 1])
			{
				LCS_index.push_back(make_pair(i - 1, j - 1));
				i--;
				j--;
			}

			else if (DP[i-1][j] == DP[i][j])
			{
				i--;
			}
			else if (DP[i][j-1] == DP[i][j])
			{
				j--;
			}
	}

	reverse(LCS_index.begin(), LCS_index.end());
	/*for (int i = size - 1; i >= 0; i--)
	{
		cout << LCS_index[i].first << " ";
	}
	cout << endl;
	for (int j = size - 1; j >= 0; j--)
	{
		cout << LCS_index[j].second << " ";
	}*/
	for (int i = 0; i < LCS_length; i++)
	{
		cout << LCS_index[i].first << " ";
	}
	cout << endl;
	for (int i = 0; i < LCS_length; i++)
	{
		cout << LCS_index[i].second << " ";
	}
}

int main()
{ 
	int n;
	cin >> n;
	vector<int> A(n);
	vector<int> B(n);
	vector<vector<int>> DP(n+1, vector<int>(n+1, 0));
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> B[i];

	}
	int LCS_length = SizeOfLongestSubSeq(A, B, DP);
	//cout << "Size of LCS:\t" << LCS_length;
	cout << LCS_length;
	cout << endl;
	/*for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			cout << DP[i][j] << "  ";
		}
		cout << endl;
	}*/
	RestoreLongestSubSeq(A, B, DP, LCS_length);
}
