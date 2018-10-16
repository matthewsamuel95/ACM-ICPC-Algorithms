#include<bits/stdc++.h>
using namespace std;
int kmp(string text, string pattern){
	if(pattern.size()==0) return -1;
	int patLen=pattern.size();
	int textLen=text.size();
	int LPS[patLen]={0};
	int i=1,j=0;

	while(i<patLen){
		if(pattern[i]==pattern[j]){
			LPS[i++]=++j;
		}
		else{
			if(j) j=LPS[j-1];
			else LPS[i++]=0;
		}
	}
	i=j=0;
	while(i<textLen){
		if(pattern[j]==text[i]){
			i++;j++;
		}
		if(j==patLen)	return i-j;
		else{
			if(i<textLen && pattern[j]!=text[i]){
				if(j) j=LPS[j-1];
				else i++;
			}
		}
	}
	return -1;
}

int main(){
	string text,pattern;
	cout<<"\nEnter text : ";
	getline(cin>>ws,text);
	cout<<"\nEnter pattern to search in "<<text<<" : ";
	getline(cin>>ws,pattern);
	int index=kmp(text,pattern);
	if(index>0){
		cout<<"\nPattern found at : "<<index<<"\n";
	}
	else{
		cout<<"\nPattern not found!\n";
	}
}