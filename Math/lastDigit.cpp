#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> last_digit[10];
	last_digit[0]={0};
	last_digit[1]={1};
	last_digit[2]={2,4,8,6};
	last_digit[3]={3,9,7,1};
	last_digit[4]={4,6};
	last_digit[5]={5};
	last_digit[6]={6};
	last_digit[7]={7,9,3,1};
	last_digit[8]={8,4,2,6};
	last_digit[9]={9,1};
	
	int a,b;
	string a1,b1;
	getline(cin,a1,' ');  	a=a1[a1.length()-1]-'0';
	getline(cin,b1,'\n');   b=b1[b1.length()-1]-'0';
	
	cout<<"\nLast digit of "<<a1<<"^"<<b1<<" is : ";
	cout<<last_digit[a%10][(b-1)%(last_digit[a%10].size())]<<endl;
	last_digit[10].clear();
	
	return 0;
}
