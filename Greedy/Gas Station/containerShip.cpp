#include<bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int> &A, vector <int> &B){
int n=A.size();
    if(n==1)
    return 0;
    int sum1=0,sum2=0,i,diff,maxa=0,maxele=0;
    for(i=0;i<n;i++){
        sum1+=(A[i]-B[i]);
        sum2+=(A[i]-B[i]);
        if(sum2<0){
            maxele=i+1;
            sum2=0;
        }
    }
    if(sum1<0){
        return -1;
    }
    return maxele%n;
}
int main()
{
  int n,i,x;
 printf("Enter n\n");
 vector<int> gas,cost;
 scanf("%d",&n);
 printf("Enter gas at each station\n");
 for(i=0;i<n;i++){
   scanf("%d",&x);
   gas.push_back(x);
 }
 printf("Enter costs\n");
 for(i=0;i<n;i++){
   scanf("%d",&x);
   cost.push_back(x);
 }
 printf("Minimum starting Index is %d\n",canCompleteCircuit(gas,cost));
  return 0;
}
