#include<bits/stdc++.h>
#define ll long long;
using namespace std;

int s[100];
int sn=INT_MIN;

int build(int v[],int s[],int pos,int start,int end)
{
	if(start==end)
		{s[pos]=v[start];
			cout<<pos<<"#"<<s[pos]<<" ";
			if(pos>sn)
				sn=pos;
			return s[pos];}
			// cout<<pos<<" ";
		int mid=(start+end)/2;
		
		s[pos]=min(build(v,s,2*pos+1,start,mid),
		build(v,s,2*pos+2,mid+1,end));
		if(pos>sn)
				sn=pos;
		cout<<pos<<"#"<<s[pos]<<" ";
		return s[pos];
}

int buildtree(int v[],int n)
{
	// cout<<v.size()-1;
	build(v,s,0,0,n-1);
	return 0;
}

void disp(int n)
{
	// vector<int>::iterator i;
	int i=0;
	for(i=0;i!=2*n+5;i++)
	// for(i=0;i<sizeof(t)/sizeof(int);i++)
		cout<<s[i]<<" ";
}

int rmq(int qlow,int qhigh,int high,int low,int pos)
{
	if(qlow<=low&&qhigh>=high)//the query overlaps the segment tree nodes
		return s[pos];
	if(qlow>high||qhigh<low)//no overlap
		return INT_MAX;
	int mid=(high+low)/2;
	return min(rmq(qlow,qhigh,mid,low,2*pos+1),rmq(qlow,qhigh,high,mid+1,2*pos+2));
}

int main()
{
	int n=0,i=0,a=0,v[100],qlow=0,qhigh=0;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>v[i];
	buildtree(v,n);
	cout<<endl;
	disp(n);
	cout<<endl;
	cin>>qlow>>qhigh;
	cout<<rmq(qlow,qhigh,n-1,0,0);
	return 0;
}