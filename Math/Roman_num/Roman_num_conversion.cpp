#include<bits/stdc++.h>
using namespace std;
int main(){
	int i;
	cin>>i;
	while(i--){
		cout<<i<<"=";
		int n=i;
		int a[7]={1,5,10,50,100,500,1000};
		char b[7]={'I','V','X','L','C','D','M'};
		int j=6;
		while(n>0){
			if(n<4*a[j]){
					if(n==9){
			cout<<"IX";
		      break;}
		      else if(n>=90&&n<100){
		      	cout<<"XC";
		      	n=n%90;
			  }
			  else if(n>=900&&n<1000){
			  	cout<<"CM";
			  	n=n%900;
			  }
				int c=n/a[j];
				while(c--){
					cout<<b[j];
				}
				n=n%a[j];
			}
			else if(n>=4*a[j]){
				cout<<b[j]<<b[j+1];
				n=n%a[j];
			}
			else 
			continue;
			j--;
		}
		cout<<endl;
	}
	return 0;
}
