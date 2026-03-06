#include <iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string>
using namespace std;

int SizeOfLongestSubSeq(const string& S, vector<vector<int>>& DP)
{
	int size = DP.size();
	for (int i = 0; i < size; i++)
	{
		DP[i][i] = 1;
	}
	for (int i = 0; i < size - 1; i++)
	{
		if (S[i] == S[i + 1])
		{
			DP[i][i + 1] = 2;
		}
		else
		{
			DP[i][i + 1] = 1;
		}
	}

	for (int range = 3; range <= size; ++range)
	{
		for (int i = 0; i <= size - range; ++i)
		{
			int j = i + range - 1;
			if (S[i] == S[j])
			{
				DP[i][j] = DP[i + 1][j - 1] + 2;  
			}
			else
			{
				DP[i][j] = max(DP[i + 1][j], DP[i][j - 1]); 
			}
		}
	}
	return DP[0][size - 1];
}
string RestoreLongestSubSeq(const string& S, vector<vector<int>>& DP, int LCS_Length)
{
	int size = DP.size();
	string palindrome;

	for (int i = 0, j = size - 1; i<=j; )
	{
		
			if (S[i] == S[j])
			{
				palindrome.push_back(S[i]);
				i++;
				j--;
			}

			else if (DP[i][j-1] == DP[i][j])
			{
				j--;
			}
			else if (DP[i+1][j] == DP[i][j])
			{
				i++;
			}
	}
	string rev_palindrome(palindrome.size(), ' ');
	reverse_copy(palindrome.begin(), palindrome.end(), rev_palindrome.begin());
	if (LCS_Length % 2 != 0)
	{
		palindrome.pop_back();
	}
	palindrome += rev_palindrome;

	return palindrome;
}

int main()
{ 
	ifstream input("input.txt");
	ofstream output("output.txt");

	string S;
	getline(input, S);
	int size = S.length();
	vector<vector<int>> DP(size, vector<int>(size, 0));

	int LCS_length = SizeOfLongestSubSeq(S, DP);

	//cout << "Size of LCS:\t" << LCS_length;
	output << LCS_length;
	output << endl;
	/*for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
	{
			cout << DP[i][j] << "  ";
	}*/
	//cout << endl;
	//}
	output<<RestoreLongestSubSeq(S, DP, LCS_length);
}
