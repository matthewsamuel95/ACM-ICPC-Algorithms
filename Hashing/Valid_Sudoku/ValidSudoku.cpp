/*
Determine if a Sudoku is valid.
The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.

The input corresponding to the above configuration :
53..7....
6..195...
.98....6.
8...6...3
4..8.3..1
7...2...6
.6....28.
...419..5
....8..79
*/
#include <bits/stdc++.h>

using namespace std;

int is_Valid_Rows_And_Columns(vector<vector<char> > &sudokuBoard)
{
	
	for (int r = 0; r < 9; ++r)
	{
		unordered_set<char>  row_set;
		for (int c = 0; c < 9; ++c)
		{

			int cell_Value=sudokuBoard[r][c];
			if(cell_Value=='.')
			{
				continue;	
			}
			// if(cell_Value < '1' || cell_Value >'9')
			// 	return 0;
			if(row_set.find(cell_Value)!=row_set.end())
		    {
		        return 0;
		    }
		    else
		    {
		        row_set.insert(cell_Value);
		    }
		}
		row_set.clear();
	}
	for (int c = 0; c < 9; ++c)
	{
		unordered_set<char>  col_set;
		for (int r = 0; r < 9; ++r)
		{
			int cell_Value=sudokuBoard[r][c];
			if(cell_Value=='.')
			{
				continue;	
			}
			// if(cell_Value < '1' || cell_Value >'9')
			// 	return 0;
			if(col_set.find(cell_Value)!=col_set.end())
		    {
		        return 0;
		    }
		    else
		    {
		        col_set.insert(cell_Value);
		    }
		}
		col_set.clear();
	}
	return 1;
}

int is_Valid_blocks(vector<vector<char> > &sudokuBoard)
{
	unordered_set<char> block_set;

	for (int row_block = 0; row_block < 3; ++row_block)
	{
		for (int col_block = 0; col_block < 3; ++col_block)
		{
			unordered_set<char> block_set;

			for (int min_row = 0; min_row < 3; ++min_row)
			{
				for (int min_col = 0; min_col < 3; ++min_col)
				{
					int r=row_block*3+min_row;
					int c=col_block*3+min_col;
					int cell_Value=sudokuBoard[r][c];

					if(cell_Value=='.')
					{
						continue;
					}
					// if(cell_Value < '1' || cell_Value >'9')
					// 	return 0;
					if(block_set.find(cell_Value)!=block_set.end())
				    {
				        return 0;
				    }
				    else
				    {
				        block_set.insert(cell_Value);
				    }
				}
			}
			block_set.clear();
		}
	}
	return 1;
}



int is_Valid(vector<vector<char> > &sudokuBoard)
{
	if (!is_Valid_Rows_And_Columns(sudokuBoard))
	{
		return 0;
	}
	if(!is_Valid_blocks(sudokuBoard))
	{
		return 0;
	}
	return 1;
}





int main()
{

	vector<string> A;
	vector<vector<char> > sudokuBoard(9,vector<char> (9));
	string x;
	for (int i = 0; i < 9; ++i)
	{
		cin >> x;
		A.push_back(x); 
	}

	for (int i = 0; i < 9; ++i)
	{
		int k=0;
		while(A[i][k]!='\0')
		{
			sudokuBoard[i][k]=A[i][k];
			k++;
		}
	}
	int ans=is_Valid(sudokuBoard);
	cout << ans <<endl;
}
