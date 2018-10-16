/*
	 Problem : Given two strings find the minimal number of edit operations (insertion, deletion or substitution)
	 to modify a string from one to the other.
*/

#include <string>
#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;

int min(int x,int y,int z){
	return x<((y<z)?y:z)?x:((y<z)?y:z);
}

int edit(vector< vector<int> > &table, string input1,string input2){
		//how many edits will it take to convert an empty string into the input strings
		for(int k=0;k<=input2.length();k++)
				table[0][k]=k;
		for(int k=0;k<=input1.length();k++)
				table[k][0]=k;	
		for(int k=1;k<=input1.length();k++){
			for(int r=1;r<=input2.length();r++){
				//if 2 characters are the same 
				//the edit distance is calculated without these characters
				if(input1.at(k-1)==input2.at(r-1))
						table[k][r]=table[k-1][r-1];
				else
						//diagonal replace characters 
						//insertion table[k][r-1]
						//deletion table[k-1][r]
						table[k][r]=min(table[k][r-1],table[k-1][r-1],table[k-1][r])+1;
			}
		}
		return table[input1.length()][input2.length()];
}

int main(){
	string input1,input2;
	cin>>input1>>input2;
	vector< vector<int> > table(input1.size()+1, vector<int>(input2.length()+1,0));
	int editDistance = edit(table,input1,input2);
	cout<<"Min Edit Distance: "<<editDistance<<endl;
	//backtrack and find what the minimum operations are needed to modify a string from one to the other
	int r=input2.length();
	int c=input1.length();
 	if(editDistance==1){
 		 if(1==table[r-1][c-1]+1){
			cout<<"replace"<<endl;
		}
		else if(1==table[r-1][c]+1){
			cout<<"delete"<<endl;
 		}
		else if(1==table[r][c-1]+1){
			cout<<"insertion"<<endl;
  	}
  }
 	else{
		while(c!=0 && r!=0){
			if(input1[c-1]==input2[r-1]){
				c--;
				r--;
			}
			else if(table[r][c]==table[r-1][c-1]+1){
				cout<<"replace"<<endl;
				c--;
				r--;
			}
			else if(table[r][c]==table[r-1][c]+1){
				cout<<"delete"<<endl;
				r--;
			}
			else if(table[r][c]==table[r][c-1]+1){
				cout<<"insertion"<<endl;
				c--;
			}
		}
	}	
}
