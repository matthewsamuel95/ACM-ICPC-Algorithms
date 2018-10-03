#include <bits/stdc++.h>

using namespace std;

int maximum(int a, int b)
{
	return a>b ? a:b;
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	int min = 1000000,max = -1000000,sum = 0;
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
		if(arr[i] > 0)
		{
			sum += arr[i];
			if(arr[i]%2 == 1 && arr[i] < min)
			{
				min = arr[i];
			}
		}
		else if(arr[i] < 0)
		{
			if(abs(arr[i])%2 == 1 && arr[i] > max)
			{
				max = arr[i];
			}
		}
	}
	if(sum%2 == 0)
	{
		sum = maximum(sum-min,sum+max);
	}
	cout << sum << endl;
}
