//Swapping two numbwer using XOR

#include<bits/stdc++.h>
using namespace std;
void XorSwapping(int a,int b){
	a=a^b;
	b=b^a;
	a=a^b;
	cout<<a<<" "<<b<<endl;
}
int main(){
	int a=5;
	int b=7;
	XorSwapping(a,b);
	return 0;
}
