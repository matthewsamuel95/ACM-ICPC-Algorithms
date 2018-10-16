// sol.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <bits/stdc++.h>
/* Dynamic Programming solution to construct Maximum Sum Increasing Subsequence */

#include <cmath>
#include <cstdio>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


typedef vector<int> VI;

// Function to construct Maximum Sum Increasing Subsequence
VI calcMaxSumIS(VI arr)
{
	int n = arr.size();

	// L[i] stores the Maximum Sum Increasing Subsequence that ends with arr[i]
	vector<VI> L(n);

	// msis[i] stores the Maximum Sum of Increasing Subsequence that
	// ends with arr[i]
	VI msis(n);

	// L[0] is equal to arr[0]
	L[0].push_back(arr[0]);
	msis[0] = arr[0];

	// start from index 1
	for (int i = 1; i < n; i++)
	{
		// for every j less than i
		for (int j = 0; j < i; j++)
		{
			// L[i] = {MaxSum(L[j])} + arr[i] where j < i and arr[j] < arr[i]
			if ((arr[i] > arr[j]) && (msis[i] < msis[j]))
			{
				L[i] = L[j];
				msis[i] = msis[j];
			}
		}
		// L[i] ends with arr[i]
		L[i].push_back(arr[i]);
		msis[i] += arr[i];

		// L[i] now stores Maximum Sum Increasing Subsequence of arr[0..i]
		// that ends with arr[i]
	}

	int maxIndex = 0;
	int max = msis[0];

	// find max
	for (int i = 1; i < n; i++)
		if (msis[i] > max)
		{
			max = msis[i];
			maxIndex = i;
		}

	// max will contain result
	return L[maxIndex];
}

int main() {
	ifstream infile("test1.txt");
	if (infile)
	{
		VI arr;
		string s;
		int a;
		while(true) {
			try {
				getline(infile,s);
				a = stoi(s);
			}
			catch (...) {
				break;
			}
			arr.push_back(a);
		}
		auto res= calcMaxSumIS(arr);
		for (auto r : res)
			cout << r << " ";
		cout << endl;
	}
}