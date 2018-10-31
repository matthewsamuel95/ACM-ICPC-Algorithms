#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<int> row_c,col_c,mai_c,opp_c;
void printBoard(vector<vector<int> > board){
	static int k = 1;
	cout<<"Board "<<k++<<":\n";
	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[i].size();j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
bool isSafe(int row,int col){
	if(row_c.find(row)!=row_c.end())
		return false;
	if(col_c.find(col)!=col_c.end())
		return false;
	if(mai_c.find(row-col)!=mai_c.end())
		return false;
	if(opp_c.find(row+col)!=opp_c.end())
		return false;
	return true;
}
void setBoard(vector<vector<int> >&board, int row,int col){
	board[row][col] = 1;
	row_c.insert(row);
	col_c.insert(col);
	mai_c.insert(row-col);
	opp_c.insert(row+col);
}
void unsetBoard(vector<vector<int> >&board, int row,int col){
	board[row][col] = 0;
	row_c.erase(row);
	col_c.erase(col);
	mai_c.erase(row-col);
	opp_c.erase(row+col);	
}
void solveBoard(vector<vector<int> > &board,int row){
	if(row==board.size()){
		printBoard(board);
		return;
	}
	for(int i=0;i<board.size();i++){
		if(isSafe(row,i)){
			setBoard(board,row,i);
			solveBoard(board,row+1);
			unsetBoard(board,row,i);
		}
	}
}
int main(){
	cout<<"Enter size of board: ";
	int n; cin>>n;
	vector<vector<int> > board = vector<vector<int> >(n,std::vector<int> (n,0));
	solveBoard(board,0);
}
