// sol.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <bits/stdc++.h>

#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef map<char, int> MI;
typedef vector<string> VS;

string trim(const string& str)
{
	size_t first = str.find_first_not_of(" ");
	if (first == string::npos)
	{
		return "";
	}
	size_t last = str.find_last_not_of(" ");
	return str.substr(first, (last - first + 1));
}


void solve(VS& words) 
{
	//solve
	map<MI, VS> res;
	for (auto w : words) {
		map<char, int> freqs;
		for (auto c : w) {
			freqs[c]++;
		}
		res[freqs].push_back(w);
	}
	//and print in Python style ^)
	cout << "[";
	bool fcont = false;
	for (auto f : res) {
		if (fcont)
			cout << ",";
		cout << endl;
		cout << " [ ";
		bool flag = false;
		for (auto& w : f.second) {
			if (flag)
				cout << ", ";
			cout << w;
			flag = true;
		}
		cout << " ]";
		fcont = true;
	}
	cout << endl << "]" << endl;
}

int main() {
	VS words;
	ifstream infile("test1.txt");
	if (infile)
	{
		while (true) {
			string word;
			getline(infile, word, ',');
			word = trim(word);
			if (word.empty())
				break;
			words.push_back(word);
		}
		solve(words);
	}
}