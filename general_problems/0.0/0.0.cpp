#include <iostream>
#include<fstream>
#include<unordered_set>
using namespace std;

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	int temp;
	unordered_set<int> numbers;

	if (input.is_open())
	{
		while (input >> temp)
		{
			numbers.insert(temp);
		}
	}
	else cout << "Input file not opened";

	long long sum = 0;

	for (int num : numbers)
	{
		sum += num;
	}

	if (output.is_open())
	{
		output << sum;
	}
	else cout << "Output file not opened";
}