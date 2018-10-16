/*
	Problem: Given a binary matrix, find out the maximum size square sub-matrix with all 1s.
*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

int min(int x,int y,int z){
	return x<((y<z)?y:z)?x:((y<z)?y:z);
}


int maxSquare(vector< vector<int> > &matrix,int row,int col) {
	vector< vector<int> > temp(row, vector<int>(col, 0));
	int max = 0;
	for(int k=0;k<matrix.size();k++)
	{
		temp[k][0]=matrix[k][0];
		if(temp[k][0]>max)
			max=temp[k][0];
	}
	for(int k=0;k<matrix[0].size();k++)
	{
		temp[0][k]=matrix[0][k];
		if(temp[0][k]>max)
			max=temp[k][0];
	}
	for(int r=1;r<matrix.size();r++){
		for(int c=1;c<matrix[r].size();c++){
			if(matrix[r][c]==1){
				temp[r][c]=min(temp[r][c-1],temp[r-1][c-1],temp[r-1][c])+1;
				if(temp[r][c]>max)
					max=temp[r][c];
			}
		}
	}
	return max;
}

int main(){
	int row,col;
	cin>>row>>col;
	vector< vector<int> > matrix(row, vector<int>(col, 0));
	//input for the matrix
	for(int r=0;r<matrix.size();r++){
		for(int c=0;c<matrix[r].size();c++){
			cin>>matrix[r][c];
 		}
	}
	int maxSubSquare=maxSquare(matrix,row,col);
	cout<<"Max Sub Square: "<<maxSubSquare<<" x "<<maxSubSquare<<endl;
}
