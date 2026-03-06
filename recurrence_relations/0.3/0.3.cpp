#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int mod = 1e9 + 7;

long long binDegreeRaising(const int a, int degree, const int mod)
{
	if (degree == 0)		return 1;
	if (degree == 1)		return a % mod;

	long long result = binDegreeRaising(a, degree / 2, mod) % mod;
	result = (result * result) % mod;

	if (degree % 2 != 0)
	{
		result = (result * (a % mod)) % mod;
	}

	if (result < 0)			result += mod;

	return result;

}


long long multiFact(const int end, int start = 1)
{
	if (end == 0)	return 1;

	long long result = 1;
	while (start <= end)
	{
		result = (result * start) % mod;
		//cout << start << endl;
		start++;
	}
	return  (result) % mod;
}

long long Combination(const int K, const int N)
{
	if (K >= N - K)
	{
		return (multiFact(N, K + 1) * binDegreeRaising(multiFact(N - K), mod - 2, mod)) % mod;
	}
	else
	{
		return (multiFact(N, N - K + 1) * binDegreeRaising(multiFact(K), mod - 2, mod)) % mod;
	}
}

int main()
{
	int N;
	int K;
	cin >> N >> K;

	cout << Combination(K, N);
}