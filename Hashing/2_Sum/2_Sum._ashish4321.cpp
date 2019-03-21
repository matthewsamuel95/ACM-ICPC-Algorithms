#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
	ll val;
	ll pos;
};

bool cmp(node a, node b)
{
	return (a.val<b.val);
}

int main(void)
{
	// Input number of elements of array
	ll n;
	cin>>n;
	// Initialize the struct for n elements
	node nums[n];
	ll a;
	for(ll i=0;i<n;i++)
	{
		cin>>a;
		nums[i].val=a;
		nums[i].pos=i;
	}
	// sort the struct according to val
	sort(nums,nums+n,cmp);
	// Input target sum required
	ll target;
	cin>>target;
	// To find two indices of array whose sum is target
	ll low=0;
	ll high=n-1;
	ll sum=INT_MIN;
	while(sum!=target)
	{
		sum=(nums[low].val+nums[high].val);
		if(sum>target)
		{
			high--; 
		}
		else if(sum<target)
		{
			low++;
		}
		else
		{
			break;
		}
	}
	cout<<nums[low].pos<<" "<<nums[high].pos;
	return 0;
}