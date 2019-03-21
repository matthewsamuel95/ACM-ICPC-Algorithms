#include<bits/stdc++.h>
using namespace std;
struct object
{
	float weight;
	float profit;
};
// understanding this function is very important
// this function will tell the sort function that how to sort the objects
bool HowToSort(struct object first,struct object second)
{
	float x=first.profit/first.weight;
	float y=second.profit/second.weight;
	return (x>y?true:false);
}
int main()
{
	int capacity,n,i,size;
	float totalprofit=0;
	cout<<"enter total capacity=";
	cin>>capacity;
	cout<<"enter total no. of objects=";
	cin>>n;
	struct object obj[n];
	for(i=0;i<n;i++)
	{
		cout<<"enter profit and weight of object "<<i+1<<": ";
		cin>>obj[i].profit>>obj[i].weight;
	}
	size=sizeof(obj)/sizeof(obj[0]);
	// custum sorting
	sort(obj,obj+size,HowToSort);
	for(i=0;i<n;i++)
	{	
		// check if there is enough capacity
		// and object can be put completely into the knapsack
		if(capacity>0 && obj[i].weight<=capacity)
		{
			capacity=capacity-obj[i].weight;
			totalprofit=totalprofit+obj[i].profit;
		}
		else
		{
			break;
		}
	}
	// there is still some space availble but
	// object can't be filled completely
	// so we will be adding some fraction of it
	if(capacity>0)
	{
		totalprofit=totalprofit+(obj[i].profit/obj[i].weight)*capacity;
	}
	cout<<"Maximum profit is: "<<totalprofit<<"\n";
}
