#include <bits/stdc++.h>
#define N 100000
using namespace std;

/* creating lps array (longest proper prefix) 
		proper prefix - prefix with whole string not allowed */
int lps[N];

void LPSArray(string pattern){
	int i=1,length = 0;
	lps[0] = 0;	// lps[0] is always 0

	int n = pattern.size();

	while(i < n){
		if(pattern[i] == pattern[length]){
			length++;
			lps[i] = length;
			i++;
		}
		else{
			if(length != 0){
				length = lps[length-1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMP(string text, string pattern){
	int n = text.size();
	int m = pattern.size();

	LPSArray(pattern);

	int i=0,j=0;
	while(i < n){
		if(pattern[j] == text[i]){
			i++;
			j++;
		}

		// after j successfull matches
		if(j == m){
			cout<<"Pattern found at index "<<i-j<<endl;
			j = lps[j-1];
		}
		// mismatch happened after j matches
		else if( i<n and pattern[j] != text[i]){
			if( j != 0)
				j = lps[j-1];
			else
				i++;
		}
	}
}

int main(){
	cout<<"Enter Text: ";
	string text,pattern;
	cin>>text;
	cout<<"Enter Pattern: ";
	cin>>pattern;
	KMP(text,pattern);

}
