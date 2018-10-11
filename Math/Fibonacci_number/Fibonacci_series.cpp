// t is position of index

#include<bits/stdc++.h>
using namespace std;

int fab(int t){
	if(t==1)
	return 0;
	if(t==2)
	return 1;
	else
	return fab(t-1)+fab(t-2);
}

int main(){
	int t;
	cin>>t;
	cout<<fab(t);
}
