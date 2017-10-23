/*
  Problem : Given a text of n words, and an integer M, the length in characters of a line, print the text neatly to minimize
  the number of extra spaces at the end of the lines.
*/
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <stack>

using namespace std;

void calculateCost(vector< vector<int> >&cost,vector<string> &input,int maxWidth){
	for(int k=0;k<input.size();k++){
		//for one word on a given line
		cost[k][k]=maxWidth-input[k].length();
		for(int r=k+1;r<input.size();r++){
			//for more than one word on a given line, -1 for every word needs a space between them
			cost[k][r]=cost[k][r-1]-input[r].length()-1;
		}
	}
	for(int k=0;k<input.size();k++){
		for(int r=0;r<input.size();r++){
			//invalid word placement if it is greater than the max width
			//+1 since an extra space has been given, 3 words should be 2 spaces only
			cost[k][r]++;
			if(cost[k][r]<0)
				cost[k][r]=INT_MAX;
			//other wise give it a penalty of x^2
			else
				cost[k][r]=pow(cost[k][r],2);
		}
	}
}

void print(vector< vector<int> >&cost,vector<string> &input){
	//find the best placement of the strings on each line, min penalty
	vector<int> minPenalty(cost.size(),0);
	vector<int> backtracking(cost.size(),0);
	for(int k=cost.size()-1;k>=0;k--){
		minPenalty[k]=cost[k][cost.size()-1];
		backtracking[k]=cost.size();
		for(int r=cost.size()-1;r>k;r--){
			if(cost[k][r-1]!=INT_MAX){
				if(minPenalty[k]>minPenalty[r]+cost[k][r-1]){
					minPenalty[k]=minPenalty[r]+cost[k][r-1];
					backtracking[k]=r;
				}
			}
		}
	}
	//use backtracking to print the words with the lowest penalty of spaces
	for(int k=0;k<backtracking.size();k++)
	{	
		if(k==0)
		{
			for(int r=0;r<backtracking[0];r++)
			{
				cout<<input[r]<<" ";
			}
			if(k+1<backtracking.size()){
				if(backtracking[0]!=backtracking[k+1])
					cout<<endl;
			}
		}
		else{
			for(int r=backtracking[k-1];r<backtracking[k];r++)
			{
				cout<<input[r]<<" ";
			}
			if(backtracking[k]!=backtracking[k-1])
			cout<<endl;
		}
	}
}


int main(){
	int inputSize;
	cin>>inputSize;
	vector<string> input(inputSize);
	int maxWidth;
	cin>>maxWidth;
	for(int k=0;k<inputSize;k++)
		cin>>input[k];
	//cost printing string x[0] to x[i], number of empty spaces on a given line
	vector< vector<int> > cost(inputSize, vector<int>(inputSize, 0));
	calculateCost(cost,input,maxWidth);
	print(cost,input);
}
