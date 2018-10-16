#include<bits/stdc++.h>
#define ll long long;
using namespace std;

int s[100];

int build(int v[],int s[],int pos,int start,int end)
{
	if(start==end)
		{s[pos]=v[start];
			cout<<pos<<"#"<<s[pos]<<" ";
			return s[pos];}
			// cout<<pos<<" ";
		int mid=(start+end)/2;
		
		s[pos]=(build(v,s,2*pos+1,start,mid)+
		build(v,s,2*pos+2,mid+1,end));
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

int sum(int qlow,int qhigh,int high,int low,int pos)
{
	if(qlow<=low&&qhigh>=high)//the query overlaps the segment tree nodes
		return s[pos];
	if(qlow>high||qhigh<low)//no overlap
		return 0;
	int mid=(high+low)/2;
	return (sum(qlow,qhigh,mid,low,2*pos+1)+sum(qlow,qhigh,high,mid+1,2*pos+2));
}

void updatetree(int d,int i,int low,int high,int pos)
{
	if(i<low||i>high)
		return;
	s[pos]+=d;
	if(low!=high){
	int mid=(low+high)/2;
	updatetree(d,i,low,mid,2*pos+1);
	updatetree(d,i,mid+1,high,2*pos+2);
	}
}

int update(int n,int a,int b)
{
	updatetree(a,b,0,n-1,0);
	return 0;
}

int main()
{
	int n=0,i=0,a=0,v[100],qlow=0,qhigh=0,b=0;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>v[i];
	buildtree(v,n);
	cout<<endl;
	disp(n);
	cout<<endl;
	cin>>qlow>>qhigh;
	cout<<sum(qlow,qhigh,n-1,0,0);
	cout<<"\nenter new value and index(0th based) to update!";
	cin>>a>>b;
	update(n,a-v[b],b);
	cout<<endl;
	disp(n);
	return 0;
}