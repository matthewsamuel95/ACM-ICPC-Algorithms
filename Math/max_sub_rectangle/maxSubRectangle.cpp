//Problem : Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.


#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <stack>

using namespace std;

// credit to http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
int getMaxArea(vector<int> hist, int n)
{
	// Create an empty stack. The stack holds indexes of hist[] array
	// The bars stored in stack are always in increasing order of their
	// heights.
	stack<int> s;

	int max_area = 0; // Initalize max area
	int tp; // To store top of stack
	int area_with_top; // To store area with top bar as the smallest bar

	// Run through all bars of given histogram
	int i = 0;
	while (i < n)
	{
		// If this bar is higher than the bar on top stack, push it to stack
		if (s.empty() || hist[s.top()] <= hist[i])
			s.push(i++);

		// If this bar is lower than top of stack, then calculate area of rectangle 
		// with stack top as the smallest (or minimum height) bar. 'i' is 
		// 'right index' for the top and element before top in stack is 'left index'
		else
		{
			tp = s.top(); // store the top index
			s.pop(); // pop the top

			// Calculate the area with hist[tp] stack as smallest bar
			area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

			// update max area, if needed
			if (max_area < area_with_top)
				max_area = area_with_top;
		}
	}

	// Now pop the remaining bars from stack and calculate area with every
	// popped bar as the smallest bar
	while (s.empty() == false)
	{
		tp = s.top();
		s.pop();
		area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

		if (max_area < area_with_top)
			max_area = area_with_top;
	}

	return max_area;
}

int main(){
	int row,col;
	cin>>row>>col;
	int check;
	vector< vector<int> > matrix(row, vector<int>(col, 0));
	vector<int> table(col);
	for(int r=0;r<row;r++){
		for(int c=0;c<col;c++){
			cin>>matrix[r][c];
			if(r==0)
				table[c]=matrix[r][c];
		}
	}
	int max=0;
	for(int r=0;r<row;r++){
		for(int c=0;c<col;c++)
		{
			if(matrix[r][c]==0)
				table[c]=0;
			else
				table[c]+=1;
		}
		check=getMaxArea(table,table.size());
		if(max<check)
			max=check;
	}
	cout<<max<<endl;
}
