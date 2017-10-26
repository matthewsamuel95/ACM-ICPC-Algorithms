#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string &a, string &b){
	int count[26]={};
	if((int)a.size() != (int)b.size())return 0;
	for(int i=0;i<(int)a.size();i++){
		if('a'<=a[i]&&a[i]<='z')count[a[i]-'a']++;
		if('A'<=a[i]&&a[i]<='Z')count[a[i]-'A']++;
		if('a'<=b[i]&&b[i]<='z')count[b[i]-'a']--;
		if('A'<=b[i]&&b[i]<='Z')count[b[i]-'A']--;
	}
	for(int i=0;i<26;i++)
		if(count[i]!=0)return 0;
	return 1;

}

int main(){
	string a,b;
	a = "Abc";
	b = "cab";
	if(isAnagram(a,b)){
		cout<<"Anagrams"<<endl;
	}else cout<<"Not Anagrams"<<endl;
}
