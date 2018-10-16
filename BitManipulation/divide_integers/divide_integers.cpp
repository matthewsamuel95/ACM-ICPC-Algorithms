//Divide two integers without using multiplication, division and mod operator. Print floor of division

#include<iostream>

using namespace std;

int divide(int A, int B) {
    long long int ans=0,sign;
    if(B==1||B==-1){
        if(B==1)
        return min(INT_MAX,A);
        else{
            long long int x=(long long int)A*(-1);
            return min((long long int)INT_MAX,x);
        }
    }
    sign=((A<0)^(B<0))?-1:1;
    A=abs(A);
    B=abs(B);
    while(A>=B){
        A-=B;
        ans++;
    }
    return (int)(ans*sign);
}

int main()
{
	int a,b,x;
	scanf("%d %d",&a,&b);
	printf("Division is %d\n",divide(a,b));
	return 0;
}
