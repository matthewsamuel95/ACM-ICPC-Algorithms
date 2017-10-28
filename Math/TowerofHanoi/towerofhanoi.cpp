#include<iostream>
using namespace std;

int calc_moves(int n,char start,char target,char aux){
	if(n==1){
		cout<<"Move disk 1 from "<<start<<" to "<<target<<endl;
		return 1;
	}
	calc_moves(n-1,start,aux,target);
	cout<<"Move disk "<<n<<" from "<<start<<" to "<<target<<endl;
	calc_moves(n-1,aux,target,start);
}
int main(){
	int n;
	cin>>n; //no of disks
	//assuming a: start rod, b:auxillary rod, c:target rod
	calc_moves(n,'A','C','B');
}
