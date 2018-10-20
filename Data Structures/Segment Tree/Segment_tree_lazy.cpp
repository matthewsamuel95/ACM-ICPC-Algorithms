#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define re1(x) scanf("%lld",&x)
#define re2(x,y) scanf("%lld%lld",&x,&y)
#define re3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)

ll n,q;
ll arr[100010];
struct node{
	ll t;
	ll lazy;
};
node st[500100];
void propogate(ll ss,ll se,ll si){
		if(st[si].lazy!=0){
			st[si].t+=(st[si].lazy*(se-ss+1));
			if(ss!=se){
				st[2*si+1].lazy+=(st[si].lazy);
				st[2*si+2].lazy+=(st[si].lazy);
			}
			st[si].lazy=0;
		}
		if(ss>se){
			return;
		}
		return;
}
void update(ll ss,ll se,ll qs,ll qe,ll si,ll val){
		propogate(ss,se,si);
		if(ss>se||ss>qe||se<qs){
			return;
		}
		if(ss>=qs && se<=qe){
			st[si].lazy+=val;
			propogate(ss,se,si);
			return;
		}
		ll mid=(ss+se)/2;
		update(ss,mid,qs,qe,2*si+1,val);
		update(mid+1,se,qs,qe,2*si+2,val);
		st[si].t=(st[2*si+1].t)+(st[2*si+2].t);
		return;
}
ll query(ll ss,ll se,ll qs,ll qe,ll si){
	propogate(ss,se,si);
	if(ss>se||ss>qe||se<qs){
		return 0;
	}
	if(ss>=qs && qe>=se){
		return st[si].t;
	}
	ll mid=(ss+se)/2;
	ll p1=query(ss,mid,qs,qe,2*si+1);
	ll p2=query(mid+1,se,qs,qe,2*si+2);
	return p1+p2;
}
void build(ll ss,ll se,ll si){
	if(ss>se){
		return;
	}
	if(ss==se){
		st[si].t=arr[ss];
		st[si].lazy=0;
		return;
	}
	ll mid=(ss+se)/2;
	build(ss,mid,2*si+1);
	build(mid+1,se,2*si+2);
	st[si].t=st[2*si+1].t+st[2*si+2].t;
}
int main(){
	ll t;
	re1(t);
	while(t--){
		re2(n,q);
		for(ll i=0;i<n;i+=1){
			re1(arr[i]);
		}
		for(ll i=0;i<=4*n;i++){
			st[i].t=0;
			st[i].lazy=0;
		}
		build(0,n-1,0);
		for(ll i=0;i<q;i++){
			ll type;
			re1(type);
			if(type==1){
				ll l,r;
				re2(l,r);
				l-=1;
				r-=1;
				ll xx=query(0,n-1,l,r,0);
				printf("%lld\n",xx);
			}
			else{
				ll l,r,val;
				re3(l,r,val);
				l-=1;
				r-=1;
				update(0,n-1,l,r,0,val);
			}
		}
	}
	return 0;
}
