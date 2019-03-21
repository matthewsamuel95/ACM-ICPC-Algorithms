#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	string input;
	cin >> input;
	vector<int> digits;
	for (size_t i = 0; i < input.length(); i++)
	{
		int d = input[i] - '0';
		digits.push_back(d);
	}
	
	unsigned long long max = 0;
	for (size_t i = 0; i < digits.size(); i++)
	{
		sort(digits.begin(), digits.end(), [](int a, int b) { return a < b; });
		while (next_permutation(digits.begin(), digits.end()))
		{			
			int sum = 0;
			string str = "";
			for (size_t j = 0; j < digits.size() - i; j++)
			{
				sum += digits[j];
				str += to_string(digits[j]);
			}
			if (sum % 3 == 0)
			{
				sort(str.begin(), str.end(), [](char a, char b) { return a > b; });
				int n = stoi(str);
				if (n > max) max = n;
			}
		}
	}	
	
	cout << max << endl;

	return 0;
}
