#include <iostream>
#include<vector>
using namespace std;


int main()
{
	const int mod = 1e9 + 7;
	int N;
	int K;
	cin >> N >> K;
	vector<vector<int>> mtrx(N + 1, vector<int>(N + 1));
	for (int i = 0; i <= N; i++)
	{
		mtrx[i][i] = 1;
		mtrx[i][0] = 1;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i - 1; j++)
		{
			mtrx[i][j] = (mtrx[i - 1][j - 1] + mtrx[i - 1][j]) % mod;
		}
	}
	cout << mtrx[N][K];
	return 0;
}
//моя оптимизаия в полтора раза + одномерный массив
/*const int mod = 1e9 + 7;
	int N;
	int K;
	cin >> N >> K;
	vector<int> arr(N+1, 1);

	for (int i = 2; i <= N; i++)
	{
		for (int j = i - 1; j >= (i-1)/2; j--)
		{
			arr[j] = (arr[j] + arr[j - 1]) % mod;
		}

		for (int j = 0; j <= (i - 1) / 2; j++)
		{
			arr[j] = arr[i - j];
		}
	}

	for (int i = 0; i <= N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << arr[K];*/