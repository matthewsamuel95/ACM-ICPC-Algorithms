#include <iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter any number: "<<endl;
	cin>>n;
	cout<< (n&1?"Number is Odd":"Number is Even")<<endl;
}
