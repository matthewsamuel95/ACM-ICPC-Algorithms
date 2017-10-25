#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void subset_sum(vector<int>& given_set, int given_sum)
{
	sort(given_set.begin(), given_set.end());
	for(int i=0; i<given_set.size();i++)
	{
		for(int m=i+1;m<given_set.size();m++)
		{
			int test_sum=given_set[i]+given_set[m];
			if (test_sum==given_sum) cout<<"There is a subset ("<<given_set[i]<<','<<given_set[m]<<") with sum "<<given_sum<<'.'<<endl;
		}
	}
};

int main()
{
	//inputs
	int given_sum=9;
	int my_list[]={3,34,4,12,5,2};
	
	vector<int> given_set(my_list, my_list + sizeof(my_list)/sizeof(int));
	subset_sum(given_set, given_sum);	
}